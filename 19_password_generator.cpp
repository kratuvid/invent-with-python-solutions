#include <iostream>
#include <random>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t length = 15;
    if (argc > 1)
        length = std::stoul(argv[1]);
    length = length < 12 ? 12 : length;

    const std::string_view specials("~!@#$%^&*()_+.");

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<used_t> dist(0, 1'000'000);

    std::string password(length, 'x');

    used_t where_luns[4];
    for (used_t i=0; i < 4; i++)
    {
        while (true)
        {
            used_t random_index = dist(engine) % length;

            bool used = false;
            for (used_t j=0; j < i; j++)
            {
                if (where_luns[j] == random_index)
                {
                    used = true;
                    break;
                }
            }

            where_luns[i] = random_index;
            if (!used) break;
        }
    }
    password[where_luns[0]] = 'a' + (dist(engine) % 26);
    password[where_luns[1]] = 'A' + (dist(engine) % 26);
    password[where_luns[2]] = '0' + (dist(engine) % 10);
    password[where_luns[3]] = specials[dist(engine) % specials.size()];

    for (used_t i=0; i < length; i++)
    {
        bool occupied = false;
        for (used_t j=0; j < 4; j++)
        {
            if (where_luns[j] == i)
            {
                occupied = true;
                break;
            }
        }

        if (!occupied)
        {
            used_t category = dist(engine) % 4;
            switch (category)
            {
                case 0: password[i] = 'a' + (dist(engine) % 26);
                        break;
                case 1: password[i] = 'A' + (dist(engine) % 26);
                        break;
                case 2: password[i] = '0' + (dist(engine) % 10);
                        break;
                case 3: password[i] = specials[dist(engine) % specials.size()];
                        break;
            }
        }
    }

    std::cout << "Your super secure random password is " << password << std::endl;
}
