#include <iostream>
#include <fstream>

int main()
{
    std::string_view filename = "test.txt";
    {
        std::ofstream ofs(filename.data(), std::ios::trunc);
        ofs << "Hello!" << std::endl;
    }
    {
        std::ofstream ofs(filename.data(), std::ios::app);
        ofs << "Goodbye!" << std::endl;
    }
    {
        std::ifstream ifs(filename.data());
        char c;
        while (ifs.get(c))
        {
            std::cout << c;
        }
    }
}
