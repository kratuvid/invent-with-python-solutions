#include <iostream>
#include <random>
#include <thread>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t times = 5;
    if (argc > 1) times = std::stoul(argv[1]);

    const used_t rock = 0, paper = 1, scissors = 2;
    const char* names[3] = {"rock", "paper", "scissors"};

    std::random_device rd;

    for (used_t i=0; i < times; i++)
    {
        for (int i=0; i < 6; i++)
        {
            std::cout << '.'; std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(128));
        }
        std::cout << '\r'; std::cout.flush();

        const used_t move_one = rd() % 3, move_two = rd() % 3;
        std::cout << names[move_one] << " <-> " << names[move_two] << ": ";

        if (move_one == move_two) std::cout << "tie";
        else
        {
            used_t moves[2] = {move_one, move_two};
            int player = 0;
            for (player=0; player < 2; player++)
            {
                if (i == 1)
                {
                    moves[0] = move_two;
                    moves[1] = move_one;
                }

                if ((moves[0] == scissors && moves[1] == paper) ||
                        (moves[0] == rock && moves[1] == scissors) ||
                        (moves[0] == paper && moves[1] == rock))
                {
                    break;
                }
            }

            if (player == 0) std::cout << "one";
            else std::cout << "two";
        }
        std::cout << std::endl;
    }
}
