#include <iostream>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    for (int i=1; i <= 8; i++)
    {
        bool white = i % 2 != 0;
        for (int j=1; j <= 8; j++)
        {
            if (white) std::cout << "W ";
            else std::cout << "B ";
            white = !white;
        }
        std::cout << std::endl;
    }
}
