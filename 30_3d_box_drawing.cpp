#include <iostream>

using used_t = long;

int main(int argc, char** argv)
{
    used_t size = 2;
    if (argc > 1)
    {
        size = std::stoul(argv[1]);
    }
    if (size <= 0) return 1;

    const char sep[2][2] = {{'+', '-'}, {'/', ' '}};
    const used_t top_rows = size + 2;
    used_t tr = top_rows-1, vs = 0;
    while (tr >= 0)
    {
        used_t sep_index = (tr == top_rows-1 || tr == 0) ? 0 : 1;

        for (used_t i=0; i < tr; i++) std::cout << ' ';

        std::cout << sep[sep_index][0];
        for (used_t i=0; i < size*2; i++) std::cout << sep[sep_index][1];
        std::cout << sep[sep_index][0];

        if (tr != top_rows-1)
        {
            for (used_t i=0; i < vs; i++) std::cout << ' ';
            if (tr == 0)
                std::cout << '+';
            else
                std::cout << '|';
            vs++;
        }

        std::cout << std::endl;
        tr--;
    }

    const char sep2[2][2] = {{'+', '-'}, {'|', ' '}};
    const used_t left_rows = top_rows - 1;
    used_t lr = left_rows-1, ds = size-1;
    while (lr >= 0)
    {
        used_t sep2_index = lr == 0 ? 0 : 1;

        std::cout << sep2[sep2_index][0];
        for (used_t i=0; i < size*2; i++) std::cout << sep2[sep2_index][1];
        std::cout << sep2[sep2_index][0];

        if (lr != 0)
        {
            for (used_t i=0; i < ds; i++) std::cout << ' ';
            std::cout << '/';
            ds--;
        }

        std::cout << std::endl;
        lr--;
    }
}

/*
Size: 2
   +----+
  /    /|
 /    / |
+----+  +
|    | /
|    |/
+----+

Size: 1
  +--+
 /  /|
+--+ +
|  |/
+--+
*/
