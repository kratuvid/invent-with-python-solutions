#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    using used_t = long long;
    using used2_t = unsigned long long;

    std::vector<std::pair<used_t, used2_t>> freq;
    if (argc > 1)
    {
        for (int i=1; i < argc; i++)
        {
            auto item = std::stoll(argv[i]);

            bool exists = false;
            used2_t exists_index;
            for (unsigned i=0; i < freq.size(); i++)
            {
                if (freq[i].first == item)
                {
                    exists = true;
                    exists_index = i;
                    break;
                }
            }

            if (exists)
            { 
                freq[exists_index].second++;
            }
            else
            {
                freq.push_back(std::make_pair(item, 1));
            }
        }
    } else return 1;

    const std::pair<used_t, used2_t> *mode = &freq[0];
    for (const auto& item : freq)
    {
        if (item.second > mode->second)
            mode = &item;
    }

    std::cout << "Frequencies: ";
    for (const auto& item : freq)
    {
        std::cout << item.first << ":" << item.second << " ";
    }
    std::cout << std::endl;

    std::cout << "Mode: " << mode->first << std::endl;
}
