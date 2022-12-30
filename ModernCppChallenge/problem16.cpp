#include <iostream>
#include <array>
#include <string>
#include <sstream>

class ipv4 {
    std::array<uint8_t, 4> data;
public:
    constexpr ipv4() : ipv4(0,0,0,0){}
    constexpr ipv4(uint8_t const a,uint8_t const b,
                   uint8_t const c,uint8_t const d):
                    data{{a,b,c,d}}{}
    explicit constexpr ipv4(uint32_t a)
                :ipv4(static_cast<uint8_t> ((a>>24) & 0xFF),
                     static_cast<uint8_t> ((a>>16) & 0xFF),
                     static_cast<uint8_t> ((a>>8 ) & 0xFF),
                     static_cast<uint8_t> (a & 0xFF)){}
    ipv4(ipv4 const & other) noexcept : data(other.data){}
    ipv4& operator=(ipv4 const & other) noexcept
    {
        data = other.data;
        return *this;
    }

    std::string to_string() const
    {
        std::stringstream sstr;
        sstr << *this;
        return sstr.str();
    }

    constexpr uint32_t to_uint32_t() const noexcept
    {
        return 
            (static_cast<uint32_t>(data[0] << 24) | 
             static_cast<uint32_t>(data[1] << 16) |
             static_cast<uint32_t>(data[2] << 8) |
             static_cast<uint32_t>(data[3]));
    }

    friend std::ostream& operator<<(std::ostream& os, const ipv4& a)
    { 
        os << static_cast<int>(a.data[0]) << '.'
           << static_cast<int>(a.data[1]) << '.'
           << static_cast<int>(a.data[2]) << '.'
           << static_cast<int>(a.data[3]);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ipv4& a)
    { 
        uint8_t d1, d2, d3;
        int b1, b2, b3, b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if (d1 == '.' && d2 == '.' && d3 == '.')
            a = ipv4(b1, b2, b3, b4);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }

    ipv4& operator++()
    {
        *this = ipv4(1 + to_uint32_t());
        return *this;
    }

    ipv4 operator++(int)
    {
        ipv4 result(*this);
        ++(*this);
        return result;
    }

    friend bool operator==(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return a1.data == a2.data;
    }
    
    friend bool operator!=(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return !(a1 == a2);
    }

    friend bool operator<(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return a1.to_uint32_t() < a2.to_uint32_t();
    }

    friend bool operator>(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return a2 < a1;
    }

    friend bool operator<=(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return !(a1 > a2);
    }

    friend bool operator>=(ipv4 const & a1, ipv4 const & a2) noexcept
    {
        return !(a1 < a2);
    }


};

int main () 
{
    std::cout << "input range:";
    ipv4 a1,a2;
    std::cin >> a1 >> a2;
    if(a2 > a1)
    {
        for ( ipv4 a = a1; a <= a2; a++)
        {
            std::cout << a << std::endl;
        }
    }
    else
    {
        std::cerr << "invalid range !" <<std::endl;
    }
}

