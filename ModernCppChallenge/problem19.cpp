#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <list> 

template <typename C, typename... Args>
void push_back(C& c, Args&&... args)
{
    (c.push_back(args), ...);
}

int main()
{
    std::vector<int> v;
    push_back(v, 21, 2, 3, 4);
    std::copy(std::cbegin(v), std::cend(v),
            std::ostream_iterator<int>(std::cout, " "));
    
    std::list<int> l;
    push_back(l, 1, 2, 3, 4);
    std::copy(std::cbegin(l), std::cend(l),
            std::ostream_iterator<int>(std::cout," "));
}