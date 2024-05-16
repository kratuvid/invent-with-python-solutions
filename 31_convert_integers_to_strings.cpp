#include <iostream>
#include <string>

using used_t = int;

int main(int argc, char** argv)
{
    used_t integer = 42;
    if (argc > 1) integer = std::stoi(argv[1]);

    std::string in_str;

    used_t integer_clone = integer < 0 ? -integer : integer;
    do
    {
        used_t digit = integer_clone % 10;
        integer_clone = integer_clone / 10;
        in_str += '0' + digit;
    } while (integer_clone != 0);
    if (integer < 0) in_str += '-';

    for (used_t i=0; i < in_str.size()/2; i++)
    {
        auto ri = in_str.size()-i-1;
        char l = in_str[i];
        in_str[i] = in_str[ri];
        in_str[ri] = l;
    }

    std::cout << "Input: " << integer << ", output: " << in_str << std::endl;
}
