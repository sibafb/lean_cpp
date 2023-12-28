#include <map>
#include <string_view>
#include <numeric>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <iostream>

std::map<char, double> analyze_text(std::string_view text)
{
    std::map<char, double> frequencies;
    for (char ch = 'a'; ch <= 'z'; ch++)
        frequencies[ch] = 0;

    for (auto ch : text)
    {
        if (isalpha(ch))
            frequencies[tolower(ch)]++;
    }

    auto total = std::accumulate(
        std::cbegin(frequencies), std::cend(frequencies),
        0ULL,
        [](auto const sum, auto const & kvp) {
            return sum + static_cast<unsigned long long>(kvp.second);
        });

    std::for_each(
        std::begin(frequencies), std::end(frequencies),
        [total](auto & kvp) {
            kvp.second = (100.0 * kvp.second) / static_cast<double>(total);
        });
        
    return frequencies;
}
    
int main()
{
    auto result = analyze_text(R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit, )"
                    R"(sed do eiusmod tempor incididunt ut labore et dolere magna aliqua.)");
    
    for (auto const & [ch, rate] : result)
    {
        std::cout << ch << " : "
                  << std::fixed
                  << std::setw(5) << std::setfill(' ')
                  << std::setprecision(2) << rate << std::endl;
    }
}