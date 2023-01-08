#include <iostream>
#include <algorithm>

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;

    while (i <= j)
    {
        while (i <= j && *i <= pivot) i++;
        while (i <= j && *j > pivot) j--;
        if (i < j) std::iter_swap(i, j);
    }
    std::iter_swap(i - 1, first);
    return i - 1;
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last)
{
    if (first < last)
    {
        auto p = partition(first, last);
        quicksort(first, p);
        quicksort(p +1, last);
    }
}

template <class RandomIt, class Compare>
RandomIt partitionc(RandomIt first, RandomIt last, Compare comp)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;
    while ( i <= j )
    {
        while (i <= j && comp(*i, pivot)) i++;
        while (i <= j && !comp(*j, pivot)) j--;
        if ( i < j ) std::iter_swap(i, j);
    }

    std::iter_swap(i - 1, first);

    return i - 1;
}

template <class RandomIt, class Compare>
void quicksort(RandomIt first, RandomIt last, Compare comp)
{
    if(first < last)
    {
        auto p = partitionc(first, last, comp);
        quicksort(first, p, comp);
        quicksort(p + 1, last, comp);
    }
}

int main()
{
    {
    std::vector<int> v{ 1, 5, 3, 8, 6, 2, 9, 7, 4 };
    quicksort(std::begin(v), std::end(v));

    std::array<int, 9> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    quicksort(std::begin(a), std::end(a));

    int b[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    quicksort(std::begin(b), std::end(b));
    }

    {
    std::vector<int> v{ 1, 5, 3, 8, 6, 2, 9, 7, 4 };
    quicksort(std::begin(v), std::end(v), std::greater_equal<>());
    }
}
