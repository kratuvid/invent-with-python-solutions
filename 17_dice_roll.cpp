#include <iostream>
#include <random>
#include <thread>
#include <chrono>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t times = 6;
    if (argc > 1) times = std::stoul(argv[1]);

    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<used_t> dist(1, 6);

    for (used_t i=0; i < times; i++)
    {
        std::cout << "Rolling the dice";
        for (int j=0; j < 6; j++)
        {
            std::cout << '.'; std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(128));
        }

        std::cout << " " << dist(engine) << std::endl;
    }
}
