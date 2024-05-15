#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    using used_t = long double;

    used_t temperature = 0.0;
    bool is_celcius = true;
    if (argc > 2)
    {
        temperature = std::stold(argv[1]);
        if (argv[2][0] == 'c' || argv[2][0] == 'C') is_celcius = true;
        else if (argv[2][0] == 'f' || argv[2][0] == 'F') is_celcius = false;
        else return 2;
    }
    else return 1;

    if (is_celcius)
    {
        used_t fahrenheit = temperature * (9.0L / 5.0L) + 32.0L;
        std::cout << temperature << "C = " << fahrenheit << "F" << std::endl;
    }
    else
    {
        used_t celcius = (temperature - 32.0L) * (5.0L / 9.0L);
        std::cout << temperature << "F = " << celcius << "C" << std::endl;
    }
}
