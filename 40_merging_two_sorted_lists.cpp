#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using used_t = unsigned long;

int main(int argc, char** argv)
{
    used_t size_one = 5, size_two = 9;
    if (argc > 1) size_one = std::stoul(argv[1]);
    if (argc > 2) size_two = std::stoul(argv[2]);
    if (size_one == 0 || size_two == 0) return 1;

    std::vector<used_t> one(size_one), two(size_two);
    std::random_device rd;
    for (used_t i=0; i < size_one; i++) one[i] = rd() % 50;
    for (used_t i=0; i < size_two; i++) two[i] = rd() % 50;
    std::sort(one.begin(), one.end());
    std::sort(two.begin(), two.end());

    std::cout << "One: ";
    for (auto i : one) std::cout << i << ' ';
    std::cout << std::endl;

    std::cout << "Two: ";
    for (auto i : two) std::cout << i << ' ';
    std::cout << std::endl;

    std::vector<used_t> merged(size_one + size_two);
    for (used_t i=0, j=0, n=0; n < merged.size(); n++)
    {
        if (i < size_one && j < size_two)
        {
            if (one[i] <= two[j])
                merged[n] = one[i++];
            else
                merged[n] = two[j++];
        }
        else
        {
            if (i < size_one)
                merged[n] = one[i++];
            else
                merged[n] = two[j++];
        }
    }

    std::cout << "Merged: ";
    for (auto i : merged) std::cout << i << ' ';
    std::cout << std::endl;
}
