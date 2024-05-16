#include <iostream>
#include <iomanip>

int main()
{
    using used_t = unsigned;

    for (used_t minutes=0; minutes < 24*60; minutes += 15)
    {
        used_t hours = minutes / 60;
        used_t left_minutes = minutes % 60;
        bool am = minutes < 12*60 ? true : false;

        hours = hours == 0 ? 12 : hours;
        hours = hours > 12 ? hours % 12 : hours;

        auto old_flags = std::cout.flags();
        std::cout << hours;
        std::cout << ":" << std::setfill('0') << std::setw(2) << left_minutes << " ";
        std::cout.flags(old_flags);
        if (am) std::cout << "am"; else std::cout << "pm";
        std::cout << std::endl;
    }
}
