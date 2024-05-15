#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    using used_t = unsigned long long;

    used_t number = 0;
    if (argc > 1) number = std::stoull(argv[1]);
    else return 1;

    std::cout << number << " is ";
    if (number % 2 == 0) std::cout << "even";
    else std::cout << "odd";
    std::cout << std::endl;
}
