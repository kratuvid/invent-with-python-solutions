#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv)
{
    using used_t = unsigned long long;

    char operation;
    used_t l, w, h;

    if (argc > 1)
    {
        operation = std::tolower(argv[1][0]);
    } else return 1;
    if (argc > 3)
    {
        l = std::stoull(argv[2]);
        w = std::stoull(argv[3]);
    } else return 1;
    if (operation == 'v' || operation == 's')
    {
        if (argc > 4)
            h = std::stoull(argv[4]);
        else return 1;
    }

    switch(operation)
    {
        case 'a':
            std::cout << "Area = L x W" << std::endl
                << l * w << " = " << l << " x " << w
                << std::endl;
            break;
        case 'p':
            std::cout << "Perimeter = L x 2 + W x 2" << std::endl
                << l*2 + w*2 << " = " << l << " x 2 + " << w << " x 2"
                << std::endl;
            break;
        case 'v':
            std::cout << "Volume = L x W x H" << std::endl
                << l * w * h << " = " << l << " x " << w << " x " << h
                << std::endl;
            break;
        case 's':
            std::cout << "Surface area = (L x W x 2) + (L x H x 2) + (W x H x 2)" << std::endl
                << (l*w*2) + (l*h*2) + (w*h*2) << " = "
                << "(" << l << " x " << w << " x 2) + ("
                << l << " x " << h << " x 2) + ("
                << w << " x " << h << " x 2)"
                << std::endl;
            break;
        default:
            return 5;
    }
}
