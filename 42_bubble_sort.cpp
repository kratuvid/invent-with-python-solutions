#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<int> list({2, 0, 4, 1, 3});
    if (argc > 1)
    {
        list.clear();
        for (int i=1; i < argc; i++)
        {
            list.push_back(std::stoi(argv[i]));
        }
    }

    std::cout << "List: ";
    for (auto i : list) std::cout << i << ' ';
    std::cout << std::endl;

    unsigned upto = list.size()-1;
    while (upto != 0)
    {
        for (unsigned i=0; i <= upto; i++)
        {
            if (i+1 > upto) break;

            if (list[i] > list[i+1])
            {
                auto l = list[i];
                list[i] = list[i+1];
                list[i+1] = l;
            }
        }
        upto--;
    }

    std::cout << "Sorted: ";
    for (auto i : list) std::cout << i << ' ';
    std::cout << std::endl;
}
