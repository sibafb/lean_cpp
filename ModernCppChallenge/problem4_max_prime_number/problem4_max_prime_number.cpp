//与えられた正の整数より小さい最大の素数

#include <iostream>
#include <cstdint>

bool isPrimeNumber(uint32_t number)
{
    for (int i = 2; i < (( number + 1) / 2 )  ; i++) {
        if ( number % i == 0) {
            return false;
        }
    }
    return true;
}

uint32_t maxPrimeNumber(uint32_t max)
{
    uint32_t currentNum;
    for ( currentNum = max; isPrimeNumber(currentNum) == false; currentNum --){ 
        std::cout << "Now : " << currentNum <<std::endl;}
    return currentNum;
}

int main()
{
    std::cout << "Please Input natural numeber:";
    
    uint32_t userInput;
    std::cin >> userInput;

    std::cout << "Calculating max prime number...";
    uint32_t maxPrimeNumberResult;
    maxPrimeNumberResult = maxPrimeNumber(userInput);

    std::cout << "max prime number under " << userInput << " is : " << maxPrimeNumberResult << std::endl;
}