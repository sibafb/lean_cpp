// 複数のタイムゾーンにおける打ち合わせ時刻
// 打ち合わせの参加者とそのタイムゾーンのリストが与えられたときに打ち合わせ時刻を各参加者のローカルタイムで表示する関数を書きなさい。

// std::map 
// C++20 ならstd::chrono::time_zoneを使うことができると思われる
// std::formatも使える。
// 

#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include <iomanip>
#include "date.h"
#include "tz.h"

//書籍の回答例

namespace ch = std::chrono;

struct attendee
{
    std::string Name;
    date::time_zone const * Zone;

    attendee(std::string_view name, std::string_view zone)
        : Name{name.data()}, Zone(date::locate_zone(zone.data()))
    {
    }
};

template <class Duration, class TimeZonePtr>
void print_meeting_times(
    date::zoned_time<Duration, TimeZonePtr> const & time,
    std::vector<attendee> const & attendees)
{
    std::cout
        << std::left << std::setw(15) << std::setfill(' ')
        << "Local time: "
        << time << std::endl;
    
    for (auto const & attendee : attendees)
    {
        std::cout 
            << std::left << std::setw(15) << std::setfill(' ')
            << attendee.Name
            << date::zoned_time<Duration, TimeZonePtr>(attendee.Zone, time)
            << std::endl;
    }
}

int main()
{
    std::vector<attendee> attendees{
        attendee{ "Ildiko", "Europe/Budapest" },
        attendee{ "Jens", "Europe/Berlin" },
        attendee{ "Jane", "America/New_York"}
    };

    unsigned int h, m;
    std::cout << "Hour:"; std::cin >> h;
    std::cout << "Minutes:"; std::cin >> m;

    date::year_month_day today = date::floor<date::days>(ch::system_clock::now());

    auto localtime = date::zoned_time<std::chrono::minutes>(
        date::current_zone(),
        static_cast<date::local_days>(today) + ch::hours{ h } + ch::minutes{ m });

    print_meeting_times(localtime, attendees);
}






