#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv)
{
    std::string_view text = "HeLlO, worlD!";
    if (argc > 1) text = argv[1];

    std::string title_text;

    bool last_letter = false;
    for (char c : text)
    {
        if (std::isalpha(c))
        {
            if (last_letter)
                title_text += std::tolower(c);
            else
                title_text += std::toupper(c);
            last_letter = true;
        }
        else
        {
            title_text += c;
            last_letter = false;
        }
    }

    std::cout << title_text << std::endl;
}
