#include <iostream>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t year = 2004;
    if (argc > 1) year = std::stoul(argv[1]);

    bool is_leap = false;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                is_leap = true;
            }
        }
        else is_leap = true;
    }

    std::cout << year << " is ";
    if (!is_leap) std::cout << "not ";
    std::cout << "a leap year" << std::endl;
}
