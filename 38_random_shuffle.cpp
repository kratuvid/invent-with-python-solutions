#include <iostream>
#include <vector>
#include <random>

using used_t = int;

int main(int argc, char** argv)
{
    std::vector<used_t> list({-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    if (argc > 1)
    {
        list.clear();
        for (int i=1; i < argc; i++)
        {
            list.push_back(std::stoi(argv[i]));
        }
    }

    std::cout << "Original: ";
    for (auto i : list) std::cout << i << ' ';
    std::cout << std::endl;

    std::random_device rd;
    for (unsigned i=0; i < list.size(); i++)
    {
        unsigned new_index = rd() % list.size();
        if (new_index != i)
        {
            std::cout << i << " <-> " << new_index << std::endl;
            auto l = list[i];
            list[i] = list[new_index];
            list[new_index] = l;
        }
    }

    std::cout << "Shuffled: ";
    for (auto i : list) std::cout << i << ' ';
    std::cout << std::endl;
}
