#include <iostream>
#include <thread>
#include <chrono>
#include <functional>

template <typename Time = std::chrono::microseconds, typename Clock = std::chrono::high_resolution_clock>
struct perf_timer
{
    template <typename F, typename... Args>
    static Time duration(F&& f, Args... args)
    {
        auto start =Clock::now();
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
        auto end = Clock::now();

        return std::chrono::duration_cast<Time>(end - start);
    }
};

using namespace std::chrono_literals;
void f()
{
    std::this_thread::sleep_for(2s);
}

void g( int const /*a*/, int const /*b*/)
{
    std::this_thread::sleep_for(1s);
}

int main()
{
    auto t1 = perf_timer<std::chrono::microseconds>::duration(f);
    auto t2 = perf_timer<std::chrono::microseconds>::duration(g, 1, 2);

    auto total = std::chrono::duration<double, std::nano>(t1 + t2).count();

    std::cout << total << std::endl;
}