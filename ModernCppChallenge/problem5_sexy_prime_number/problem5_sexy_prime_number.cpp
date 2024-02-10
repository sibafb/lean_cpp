//与えられた正の整数より小さい最大の素数

#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>


using uintPair = std::pair<uint32_t, uint32_t>;

bool isPrimeNumber(uint32_t number)
{
    for (int i = 2; i < (( number + 1) / 2 )  ; i++) {
        if ( number % i == 0) {
            return false;
        }
    }
    return true;
}

bool hasSexyPrimeNumber(uint32_t lower_prime_number)
{
    return isPrimeNumber(lower_prime_number + uint32_t(6));
}

void listSexyPrimeNumber(std::vector<uintPair>& sexyPrimeNumberList, uint32_t max_num)
{
    if(sexyPrimeNumberList.empty())
        std::cout << "warn : sexyPrimeNumber list is not empty";
    
    uint32_t currentNum;
    for ( currentNum = 2; currentNum < max_num - 6; currentNum ++) { 
        std::cout << "Now : " << currentNum <<std::endl;
        if (hasSexyPrimeNumber(currentNum)) {
            sexyPrimeNumberList.push_back(std::make_pair(currentNum, currentNum + 6));
        }
    }
}

void printSexyPrimeNumberList(std::vector<uintPair>& sexyPrimeNumberList)
{
    for (uintPair num : sexyPrimeNumberList) {
        std::cout << "( " << num.first << ", " << num.second <<  ") " << std::endl;
    }
}

int main()
{
    std::cout << "Please Input natural numeber:";
    
    uint32_t userInput;
    std::cin >> userInput;

    std::cout << "Calculating sexy prime number list...";
    std::vector<uintPair> sexyPrimeNumberList;
    listSexyPrimeNumber(sexyPrimeNumberList, userInput);

    std::cout << "sexy primeNumber list under " << userInput << " is : " << std::endl;
    printSexyPrimeNumberList(sexyPrimeNumberList);
}