#include <iostream>
#include <string_view>
#include <cctype>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    std::string_view text = "Hello, World!";
    if (argc > 1) text = argv[1];

    std::string encrypted(text.size(), ' ');

    for (unsigned i=0; i < text.size(); i++)
    {
        if (std::islower(text[i]))
            encrypted[i] = 'a' + (((text[i] - 'a') + 13) % 26);
        else if (std::isupper(text[i]))
            encrypted[i] = 'A' + (((text[i] - 'A') + 13) % 26);
        else
            encrypted[i] = text[i];
    }

    std::cout << "Input: " << text << std::endl;
    std::cout << "ROT13-ed: " << encrypted << std::endl;
}
