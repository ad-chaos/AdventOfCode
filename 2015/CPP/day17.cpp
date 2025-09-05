#include <iostream>
#include <unordered_map>

int main()
{
    constexpr int N             = 20;
    constexpr int TOTAL         = 150;
    int           containers[N] = {50, 44, 11, 49, 42, 46, 18, 32, 26, 40,
                                   21, 7,  18, 43, 10, 47, 36, 24, 22, 40};
    int           num_container_per_combination = 0;
    int           total                         = 0;
    int           numCombinations               = 0;
    std::unordered_map<int, int> num_containers {};

    for(int i = 0; i < (1 << N); ++i) {
        total                         = 0;
        num_container_per_combination = 0;
        for(int j = 0; j < N; ++j) {
            if(i & (1 << j)) {
                ++num_container_per_combination;
                total += containers[j];
            }
        }
        if(total == TOTAL) {
            ++numCombinations;
            if(num_container_per_combination) {
                ++num_containers[num_container_per_combination];
            }
        }
    }
    // part 1
    std::cout << numCombinations << "\n";
    // part 2
    int minimum {};
    for(auto& it: num_containers) {
        minimum = std::min(minimum, it.first);
        std::cout << it.first << ": has value - " << it.second << "\n";
    }
}
