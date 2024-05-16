#include <iostream>

using used_t = unsigned long long;

int main(int argc, char** argv)
{
    used_t begin = 34;
    if (argc > 1) begin = std::stoull(argv[1]);
    if (begin == 0) return 1;

    std::cout << begin << " -> ";
    while (begin != 1)
    {
        if (begin % 2 == 0) begin = begin / 2;
        else begin = 3 * begin + 1;
        std::cout << begin;
        if (begin != 1) std::cout << " -> ";
    }
    std::cout << std::endl;
}
