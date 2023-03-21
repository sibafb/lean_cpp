#include <iostream>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <chrono>

int main()
{
    using namespace std;
    std::time_t t = std::time(nullptr);

    fmt::print("The date is {:%Y-%m-%d}.\n", fmt::localtime(t));
    // The date is 2023-03-21.

    cout << fmt::format("Hello, {}!", "Aki") << endl;
    // Hello, Aki!

    using std::chrono::system_clock;
    using std::chrono::time_point;

    time_point<system_clock> time = system_clock::now();
    fmt::print("{:%Y-%m-%d %H:%M:%S}\n", time);
    // 2023-03-21 15:21:51
    std::cout << fmt::format("{:%Y-%m-%d %H:%M:%S}", time) << endl;
    // 2023-03-21 15:21:51
}
