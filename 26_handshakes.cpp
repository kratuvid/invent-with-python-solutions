#include <iostream>
#include <string_view>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<std::string_view> persons ({"Alice", "Bob", "Carol", "David"});
    if (argc > 1)
    {
        persons.clear();
        for (int i=1; i < argc; i++)
        {
            persons.push_back(argv[i]);
        }
    }

    std::cout << "Persons: ";
    for (auto p : persons)
    {
        std::cout << p << ' ';
    }
    std::cout << std::endl << std::endl;

    for (int i=0; i < persons.size(); i++)
    {
        for (int j=i+1; j < persons.size(); j++)
        {
            std::cout << persons[i] << " shakes hands with " << persons[j] << std::endl;
        }
    }
}
