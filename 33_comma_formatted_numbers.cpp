#include <iostream>
#include <algorithm>

int main(int argc, char** argv)
{
    using used_t = unsigned long;

    used_t number = 100'000;
    if (argc > 1)
    {
        number = std::stoul(argv[1]);
    }

    std::string in_str;
    used_t i = 1;
    do
    {
        used_t digit = number % 10;
        number = number / 10;

        in_str += '0' + digit;
        if (i % 3 == 0 && number != 0) in_str += ',';

        i++;
    } while (number != 0);

    std::reverse(in_str.begin(), in_str.end());

    std::cout << in_str << std::endl;
}
