#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    using used_t = unsigned long long;
    
    used_t n = 100;
    if (argc > 1) n = std::stoull(argv[1]);

    std::cout << n;

    used_t last_digit = n % 10;
    switch(last_digit)
    {
        case 1: std::cout << "st"; break;
        case 2: std::cout << "nd"; break;
        case 3: std::cout << "rd"; break;
        default: std::cout << "th"; break;
    }

    std::cout << std::endl;
}
