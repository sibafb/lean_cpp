// problem43をfmt のライブラリを使って解く手法
#include <iostream>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <chrono>

int main()
{
    using namespace std;
    std::time_t t = std::time(nullptr);

    fmt::print("The date is {:%Y-%m-%d}.", fmt::localtime(t));

    cout << endl;

    cout << fmt::format("Hello, {}!", "Aki") << endl;

    using std::chrono::system_clock;
    using std::chrono::time_point;
    time_point<system_clock> time = system_clock::now();
    cout << endl;
    fmt::print("{:%Y-%m-%d %H:%M:%S}", time);

    cout << endl;

    cout << fmt::format("{:%Y-%m-%d %H:%M:%S}", time) << endl;

    cout << endl;
}
