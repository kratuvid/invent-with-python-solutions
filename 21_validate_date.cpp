#include <iostream>

using used_t = long;

int main(int argc, char** argv)
{
    used_t year = 2004, month = 2, day = 31;
    if (argc > 1) day = std::stol(argv[1]);
    if (argc > 2) month = std::stol(argv[2]);
    if (argc > 3) year = std::stol(argv[3]);

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

    used_t days_in_month;
    if (month <= 7)
        days_in_month = month % 2 == 0 ? 30 : 31;
    else
        days_in_month = month % 2 == 0 ? 31 : 30;
    if (month == 2)
        days_in_month = 28 + used_t(is_leap);

    bool is_valid = true;
    if (month < 1 || month > 12) is_valid = false;
    if (day < 1 || day > days_in_month) is_valid = false;

    std::cout << day << "/" << month << "/" << year << " is ";
    if (!is_valid) std::cout << "not ";
    std::cout << "a valid date" << std::endl;
}
