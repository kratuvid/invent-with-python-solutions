#include <iostream>
#include <string_view>

int main(int argc, char** argv)
{
    std::string_view what = "Hello, World!";
    if (argc > 1) what = argv[1];

    std::string reverse(what.size(), ' ');

    for (unsigned i = 0; i < what.size(); i++)
    {
        reverse[i] = what[what.size()-i-1];
    }

    std::cout << reverse << std::endl;
}
