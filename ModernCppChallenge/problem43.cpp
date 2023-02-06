// 複数のタイムゾーンにおける打ち合わせ時刻
// 打ち合わせの参加者とそのタイムゾーンのリストが与えられたときに打ち合わせ時刻を各参加者のローカルタイムで表示する関数を書きなさい。

// std::map 
// C++20 ならstd::chrono::time_zoneを使うことができると思われる
// std::formatも使える。
// 

#include <iostream>
#include <chrono>
#include <list>
#include <map>
#include <format>
#include <string>
#include <sstream>

static std::map<std::string, std::chrono::hours> TimeZone = 
{
    {"TOKYO", std::chrono::hours(9)},
    {"NEWYORK", -std::chrono::hours(14)},
    {"BEIJING", std::chrono::hours(8)},
    {"LONDON", std::chrono::hours(0)},
};

// 打ち合わせの参加者とそのタイムゾーンのリスト
using AtendeeTimeZone = std::pair<std::string, std::string>;
using AttendeeTimeZones = std::list<AtendeeTimeZone>;


void printLocalTime(const std::chrono::system_clock::time_point& meetingTime, const AttendeeTimeZones& attendeeTimeZones)
{
    
    for (const auto atendeeTimeZone : attendeeTimeZones)
    {
        //ref : https://stackoverflow.com/questions/34857119/how-to-convert-stdchronotime-point-to-string
        std::cout << std::format("{:%h}",(meetingTime + TimeZone[atendeeTimeZone.first])) << std::endl;
        //std::cout << format("%D %T %Z\n", floor<std::chrono::hours>(meetingTime + TimeZone[atendeeTimeZone.first])) << std::endl;
        //std::chrono型が<<に対応したのはC++20。
    }
}

int main()
{
    AttendeeTimeZones attendeeTimeZones
    {
        {"Bob", "TOKYO"},
        {"Alice", "NEWYORK"},
        {"Carol", "BEJING"},
        {"Eve", "LONDON"}
    }

    printLocalTime(system_clock::now(), attendeeTimeZones);
}






