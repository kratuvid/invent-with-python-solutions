#include <iostream>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t bottles = 99;
    if (argc > 1) bottles = std::stoul(argv[1]);

    auto correct_bottle = [](used_t i) {
        if (i == 1) return "bottle";
        else return "bottles";
    };

    while (bottles != 0)
    {
        std::cout << bottles << " " << correct_bottle(bottles) << " of beer on the wall," << std::endl;
        std::cout << bottles << " " << correct_bottle(bottles) << " of beer," << std::endl;
        std::cout << "Take one down," << std::endl;
        std::cout << "Pass it around," << std::endl;
        bottles--;
        if (bottles == 0)
            std::cout << "No more bottles of beer on the wall!" << std::endl;
        else
        {
            std::cout << bottles << " " << correct_bottle(bottles) << " of beer on the wall," << std::endl;
            std::cout << std::endl;
        }
    }
}
