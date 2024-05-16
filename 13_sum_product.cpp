#include <iostream>
#include <list>

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
    }

    used_t sum = 0, product = 1;
    for (auto item : list)
    {
        sum += item;
        product *= item;
    }

    std::cout << "List: ";
    for (auto item : list) std::cout << item << " ";
    std::cout << std::endl;

    std::cout << "Sum: " << sum << ", product: " << product << std::endl;
}
