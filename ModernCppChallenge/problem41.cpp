#include <iostream>
#include "date.h"
#include "iso_week.h"

unsigned int weekday(int const y, unsigned int const m, unsigned int const d)
{
    using namespace date;
    if ( m < 1 || m > 12 || d < 1 || d >31) return 0;

    auto const dt = date::year_month_day{ year{ y }, month{ m }, day{ d } };
    auto const tiso = iso_week::year_weeknum_weekday{ dt };

    return static_cast<unsigned int>(tiso.weekday());
}

int main()
{
    auto wday = weekday(2023, 1, 6);
    std::cout << wday << std::endl;
}