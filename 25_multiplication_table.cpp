#include <iostream>
#include <iomanip>

using used_t = unsigned long;

used_t get_num_digits(used_t n)
{
    used_t digits = 0;
    do
    {
        n = n / 10;
        digits++;
    } while (n != 0);
    return digits;
}

int main(int argc, char** argv)
{
    used_t upto = 10;
    if (argc > 1) upto = std::stoul(argv[1]);

    auto orig_flags = std::cout.flags();

    for (used_t row_raw=0; row_raw <= upto+1; row_raw++)
    {
        const used_t row = row_raw - 1;
        const char first_sep = row_raw == 1 ? '-' : ' ', second_sep = row_raw == 1 ? '+' : '|';

        std::cout << std::setfill(first_sep) << std::setw(get_num_digits(upto));
        if (row_raw <= 1) std::cout << first_sep;
        else std::cout << row;

        std::cout.flags(orig_flags); std::cout << second_sep;

        for (used_t col = 1; col <= upto; col++)
        {
            std::cout << std::setfill(first_sep) << std::setw(get_num_digits(col * upto));

            if (row_raw == 0)
                std::cout << col;
            else if (row_raw == 1)
                std::cout << '-';
            else
                std::cout << row * col;

            if (col != upto)
            {
                std::cout.flags(orig_flags); std::cout << ' ';
            }
        }

        std::cout.flags(orig_flags); std::cout << std::endl;
    }
}
