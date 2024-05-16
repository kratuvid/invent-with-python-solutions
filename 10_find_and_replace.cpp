#include <iostream>
#include <string>
#include <string_view>
#include <vector>

std::string find_replace(std::string_view text, std::string_view old_str, std::string_view new_str)
{
    std::string new_text;
    std::vector<unsigned> instances;

    for (unsigned i=0; i < text.size(); i++)
    {
        bool matched = true;
        for (unsigned j=0; j < old_str.size(); j++)
        {
            if (text[i+j] != old_str[j])
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            instances.push_back(i);
        }
    }

    if (instances.empty())
    {
        new_text = text;
    }
    else
    {
        unsigned where_last = 0;
        for (unsigned i=0; i < instances.size(); i++)
        {
            new_text += std::string(text.begin() + where_last, text.begin() + instances[i]);
            new_text += new_str;
            where_last = instances[i] + old_str.size();
        }
        new_text += std::string(text.begin() + where_last, text.end());
    }

    return std::move(new_text);
}

int main(int argc, char** argv)
{
    std::string_view text, old_str, new_str;
    if (argc > 3)
    {
        text = argv[1];
        old_str = argv[2];
        new_str = argv[3];
    } else return 1;

    std::cout << "Old: " << text << std::endl;
    std::cout << "New: " << find_replace(text, old_str, new_str) << std::endl;
}
