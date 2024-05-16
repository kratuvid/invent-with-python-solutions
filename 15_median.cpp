#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
    using used_t = long long;

    std::vector<used_t> list;
    if (argc > 1)
    {
        for (int i=1; i < argc; i++)
        {
            list.push_back(std::stoll(argv[i]));
        }
    } else return 1;

    used_t sum = 0;
    for (auto item : list)
        sum += item;

    std::sort(list.begin(), list.end());

    long double median;
    if (list.size() % 2 == 0)
    {
        auto where = list.size() / 2;
        median = (list[where-1] + list[where]) / 2.0L;
    }
    else
    {
        median = list[list.size()/2];
    }

    std::cout << "Sorted list: ";
    for (auto item : list)
        std::cout << item << " ";
    std::cout << std::endl;

    std::cout << "Median: " << median << std::endl;
}
