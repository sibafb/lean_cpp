#include <iostream>

// 最大公約数
//　ユークリッドの互除法を使う
unsigned int prob2 (unsigned const int a, unsigned const int b)
{
    return (b == 0) ? a : prob2(b,a%b);
}

int main() 
{
    unsigned int a, b;
    unsigned int gcd;   
    std::cout<<"input a."<<std::endl;
    std::cin>>a;
    std::cout<<"input b."<<std::endl;
    std::cin>>b;
    
    gcd = prob2(a,b);
    std::cout<<"gcd is "<<gcd<<std::endl;
    return 0;
}
