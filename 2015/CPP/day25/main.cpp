#include <iostream>
typedef unsigned long long uint64;

int main()
{
    constexpr int row           = 2978;
    constexpr int column        = 3083;
    constexpr int total_numbers = row + column - 1;
    uint64        upper_bound   = total_numbers * (total_numbers + 1) / 2;
    constexpr int factor        = 252533;
    constexpr int mod           = 33554393;
    uint64        prev_code     = 20151125;
    uint64        next_code     = 1;
    uint64        code          = prev_code;

    for(unsigned int i = 1; i <= upper_bound - (row - 1); ++i) {
        code      = prev_code;
        next_code = (prev_code * factor) % mod;
        prev_code = next_code;
    }
    std::cout << code << "\n";
}
