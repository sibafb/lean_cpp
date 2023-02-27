#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using std::chrono::system_clock;

int main() {
    system_clock::time_point p = system_clock::now();

    std::time_t t = system_clock::to_time_t(p);
    const std::tm* lt = std::localtime(&t);
    std::cout << std::put_time(lt, "%c") << std::endl;    
}