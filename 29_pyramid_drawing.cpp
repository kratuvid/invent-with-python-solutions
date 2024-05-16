#include <iostream>

using used_t = long;

int main(int argc, char** argv)
{
    used_t base = 3;
    if (argc > 1)
    {
        base = std::stol(argv[1]);
    }
    if (base <= 0) return 1;

    used_t spaces = base / 2, dots = 1;
    while (spaces >= 0)
    {
        for (used_t i=0; i < spaces; i++) std::cout << ' ';
        for (used_t i=0; i < dots; i++) std::cout << '#';
        std::cout << std::endl;
        spaces--, dots += 2;
    }
}
