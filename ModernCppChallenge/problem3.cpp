// 最小公倍数の計算
// a と ｂの最小公倍数をdとして
// a × b / d が最小公倍数

#include <iostream>
#include <assert.h>
#include <numeric>

// C++17からは標準関数がある
//
int least_common_multiple_std(int a, int b)
{
    return std::lcm(a,b);
}

// 最小公倍数の実装
unsigned int greatest_common_divisor(int a, int b)
{
    return (b == 0)? a : greatest_common_divisor(b, a%b);
}

// C++15以前は
int least_common_multiple_origin(int a, int b)
{
    return a * b / greatest_common_divisor(a, b);
}

int main(int a, int b)
{
    std::cout << "problem3 start" << std::endl;
    assert(least_common_multiple_std(3,4) == 12);
    assert(least_common_multiple_std(5,7) == 35);
    
    assert(least_common_multiple_origin(3,4) == 12);
    assert(least_common_multiple_origin(5,7) == 35);
    std::cout << "problem3 end" << std::endl;

    return 0;
}




