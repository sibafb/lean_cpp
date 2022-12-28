#include <iostream>

// The summation of  
void prob1 ()
{
    unsigned int max;
    std::cout<<"input a number."<<std::endl;
    std::cin>>max;
    unsigned long long sum_result = 0;
    for(unsigned int i=0; i < max ;i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
        {
            sum_result +=i;
        }
    }

    std::cout<<"result: "<< sum_result << std::endl;   

}
int main() {
    prob1();
}
