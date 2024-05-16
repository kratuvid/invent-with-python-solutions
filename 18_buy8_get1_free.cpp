#include <iostream>
#include <string>

using coffee_t = unsigned long;
using price_t = float;

int main(int argc, char** argv)
{
    coffee_t count;
    price_t per_price;
    if (argc > 2)
    {
        count = std::stoul(argv[1]);
        per_price = std::stof(argv[2]);
    } else return 1;

    coffee_t free_count = count / 8;
    free_count = count % 8 == 0 ? (free_count == 0 ? 0 : free_count-1) : free_count;
    price_t price = (count - free_count) * per_price;

    std::cout << "You got " << count << " coffees" << std::endl;
    std::cout << "Of which you will get " << free_count << " free coffees" << std::endl;
    std::cout << "Your total price is ("
        << count << " - " << free_count << ") * " << per_price << " = "
        << count - free_count << " * " << per_price << " = "
        << price << std::endl;
}
