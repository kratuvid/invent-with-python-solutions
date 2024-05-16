#include <iostream>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t width = 10, height = 4;
    if (argc > 2)
    {
        width = std::stoul(argv[1]);
        height = std::stoul(argv[2]);
    }
    if (width == 0 || height == 0) return 1;

    for (used_t row=0; row < height; row++)
    {
        for (used_t col=0; col < width; col++)
        {
            if (row == 0 || row == height-1)
            {
                if (col == 0 || col == width-1)
                    std::cout << '+';
                else
                    std::cout << '-';
            }
            else
            {
                if (col == 0 || col == width-1)
                    std::cout << '|';
                else
                    std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}
