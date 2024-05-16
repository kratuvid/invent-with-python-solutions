#include <iostream>
#include <list>
#include <limits>

int main(int argc, char** argv)
{
    using used_t = long long;

    std::list<used_t> list;
    if (argc > 1)
    {
        for (int i=1; i < argc; i++)
        {
            list.push_back(std::stoll(argv[i]));
        }
    } else return 1;

    used_t min = std::numeric_limits<used_t>::max(),
           max = std::numeric_limits<used_t>::min();
    for (auto item : list)
    {
        if (item < min) min = item;
        if (item > max) max = item;
    }

    std::cout << "List: ";
    for (auto item : list) std::cout << item << " ";
    std::cout << std::endl;

    std::cout << "Min: " << min << ", max: " << max << std::endl;
}
