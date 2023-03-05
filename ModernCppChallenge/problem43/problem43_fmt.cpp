// problem43をfmt のライブラリを使って解く手法
#include <iostream>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <chrono>

#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/time_zone_base.hpp"
#include "boost/date_time/local_time_adjustor.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"

using namespace boost::posix_time;
using namespace boost::gregorian;

struct Attendee
{
    const std::string full_name_;
    const boost::posix_time::time_duration time_diff_;

    Attendee(const std::string& full_name, const boost::posix_time::time_duration& time_diff)
        : full_name_(full_name),
          time_diff_(time_diff)
        {}
};

void print_local_time(const boost::posix_time::ptime & utc_time, std::vector<Attendee> const & attendees)
{
    std::cout
        << "Local time: "
        << utc_time << std::endl;

    for (auto const & attendee : attendees)
    {
        std::cout
            << attendee.full_name_
            << utc_time + attendee.time_diff_
            << std::endl;
    }
}

#define Europe_Budapest boost::posix_time::hours(1)
#define Europe_Berlin boost::posix_time::hours(1)
#define America_New_York boost::posix_time::hours(-5)


int main()
{
    std::vector<Attendee> attendees{
        Attendee{ "Ildiko", Europe_Budapest},
        Attendee{ "Jens", Europe_Berlin },
        Attendee{ "Jane", America_New_York }
    };

    ptime now = boost::posix_time::second_clock::local_time(); 
    print_local_time(now, attendees);
}