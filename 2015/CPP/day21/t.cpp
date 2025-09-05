#include <iostream>
#include <math.h>
#include <random>
#include <string>
#include <vector>

#define log(x) std::cout << x << "\n"
#define Vector std::vector
using std::vector;

int main()
{
    vector<int> Array;
    int counter = 2;

    std::default_random_engine gen;
    do {
        std::uniform_int_distribution<int> rng(1, 49);

        int number = rng(gen);
        if(Array.empty()) {
            Array.push_back(number);
        }

        for(auto& i: Array) {
            if(!(number == i)) {
                Array.push_back(number);
                log(number);
            }
        }

    } while(counter--);
}

