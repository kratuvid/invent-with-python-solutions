#include <iostream>
#include <string_view>
#include <cctype>

using used_t = int;

int main(int argc, char** argv)
{
    std::string_view in_str = "42";
    if (argc > 1)
        in_str = argv[1];

    used_t integer = 0, place = 1;

    for (unsigned i=0; i < in_str.size(); i++)
    {
        const unsigned ai = in_str.size() - i - 1;
        if (std::isdigit(in_str[ai]))
        {
            integer += place * (in_str[ai] - '0');
            place *= 10;
        }
    }

    if (in_str[0] == '-')
        integer = -integer;

    std::cout << "Input: " << in_str << ", output: " << integer << std::endl;
}
