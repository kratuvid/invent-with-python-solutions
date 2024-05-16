#include <iostream>

int main(int argc, char** argv)
{
    using used_t = unsigned long long;

    used_t total_seconds = 30000ull;
    if (argc > 1)
        total_seconds = std::stoull(argv[1]);

    const used_t days_convert = 60ull * 60 * 24,
          hours_convert = 60ull * 60,
          minutes_convert = 60ull;

    used_t ts_clone = total_seconds;
    used_t days, hours, minutes, seconds;
    days = ts_clone / days_convert;
    ts_clone = ts_clone % days_convert;
    hours = ts_clone / hours_convert;
    ts_clone = ts_clone % hours_convert;
    minutes = ts_clone / minutes_convert;
    seconds = ts_clone % minutes_convert;

    std::cout << total_seconds << "s = ";
    if (days != 0) std::cout << days << "d ";
    if (hours != 0) std::cout << hours << "h ";
    if (minutes != 0) std::cout << minutes << "m ";
    if (seconds != 0 || (days == 0 && hours == 0 && minutes == 0)) std::cout << seconds << "s";
    std::cout << std::endl;
}
