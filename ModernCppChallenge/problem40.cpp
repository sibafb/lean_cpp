#include <iostream>
#include "date.h"

inline int number_of_days(
    int const y1, unsigned int const m1, unsigned int const d1,
    int const y2, unsigned int const m2, unsigned int const d2)
{
    using namespace date;

    return (sys_days{ year{ y1 } / month{ m1 } / day{ d1 } } -
            sys_days{ year{ y2 } / month{ m2 } / day{ d2 } }).count();
}

inline int number_of_days(date::sys_days const & first, date::sys_days const & last)
{
    return (last - first).count();   
}

int main()
{
    auto diff1 = number_of_days(2016, 9, 23, 2017, 5, 15);
    std::cout << diff1 << std::endl;

    using namespace date::literals;
    auto diff2 = number_of_days(2016_y/sep/23, 15_d/may/2017);
    std::cout << diff2 << std::endl;

}

