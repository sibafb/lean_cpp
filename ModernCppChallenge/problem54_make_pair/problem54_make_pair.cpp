#include <vector>
#include <iostream>

template <typename Input , typename Output>
void pairwise(Input begin, Input end, Output result)
{
    auto it = begin;
    while (it != end)
    {
        auto const v1 = *it++;
        if (it == end) break;
        auto const v2 = *it++;
        result++ = std::make_pair(v1, v2);
    }
}

template <typename T>
std::vector<std::pair<T, T>> pairwise(std::vector<T> const & range)
{
    std::vector<std::pair<T, T>> result;
    pairwise(std::cbegin(range), std::cend(range), std::back_inserter(result));
    return result;
}

int main()
{
    std::vector<int> v{ 1, 1, 3, 5, 8, 13, 21 };

    auto result = pairwise(v);

    for (auto const & [v1, v2] : result)
    {
        std::cout << '{' << v1 << ',' << v2 << '}' << std::endl;
    }
}