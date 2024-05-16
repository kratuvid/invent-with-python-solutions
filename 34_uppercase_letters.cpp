#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string_view text = "Hello, world!";
    if (argc > 1) text = argv[1];

    std::string upper_text;

    for (char c : text)
    {
        if (c >= 'a' && c <= 'z')
            upper_text += 'A' + (c - 'a');
        else
            upper_text += c;
    }

    std::cout << upper_text << std::endl;
}
