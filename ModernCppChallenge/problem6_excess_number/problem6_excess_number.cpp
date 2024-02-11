
#include <iostream>
#include <vector>
#include <utility>

bool isExcessNumber(uint32_t number)
{
    int sum_of_divisor = 0;
    for (int i = 2; i <= number / 2 ; i++) {
        if ( number % i == 0 ) {
            sum_of_divisor += i;
        } 
    }
    return ( sum_of_divisor > ( number ) ); // 過剰数:自分自身を除く約数の総和が自分自身より大きい
}

void listExcessNumber(std::vector<uint32_t>& excessNumberList, uint32_t max_num)
{
    if(!excessNumberList.empty()) {
        std::cout << "warn : excessNumber list is not empty";
        return;
    }
    
    uint32_t currentNum;
    for ( currentNum = 2; currentNum <= max_num; currentNum ++) { 
        if (isExcessNumber(currentNum)) {
            excessNumberList.push_back(currentNum);
        }
    }
}
void printExcessNumberList(std::vector<uint32_t>& excessNumberList)
{
    for (uint32_t num : excessNumberList) {
        std::cout << num << std::endl;
    }
}

int main()
{
    std::cout << "Please Input natural numeber:";
    
    uint32_t userInput;
    std::cin >> userInput;

    std::cout << "Calculating excess number list...";
    std::vector<uint32_t> excessNumberList;
    listExcessNumber(excessNumberList, userInput);

    std::cout << "excess number list under " << userInput << " is : " << std::endl;
    printExcessNumberList(excessNumberList);
}