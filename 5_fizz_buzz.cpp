#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    using used_t = unsigned long long;
    
    used_t upto = 100;
    if (argc > 1) upto = std::stoull(argv[1]);

    for (used_t i=1; i <= upto; i++)
    {
        bool div_3 = i % 3 == 0;
        bool div_5 = i % 5 == 0;
        
        if (div_3) std::cout << "Fizz";
        if (div_5) std::cout << "Buzz";
        if (!div_3 && !div_5) std::cout << i;
        std::cout << std::endl;
    }
}
