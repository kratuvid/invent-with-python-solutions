#include <iostream>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t cents = 128;
    if (argc > 1) cents = std::stoul(argv[1]);

    used_t left;
    used_t quarters = cents / 25;
    left = cents % 25;
    used_t dimes = left / 10;
    left = left % 10;
    used_t nickels = left / 5;
    left = left % 5;
    used_t pennies = left;

    std::cout << cents << " cents = ";
    if (quarters > 0) std::cout << quarters << " quarters ";
    if (dimes > 0) std::cout << dimes << " dimes ";
    if (nickels > 0) std::cout << nickels << " nickels ";
    if (pennies > 0 || (!quarters && !dimes && !nickels)) std::cout << pennies << " pennies ";
    std::cout << std::endl;
}
