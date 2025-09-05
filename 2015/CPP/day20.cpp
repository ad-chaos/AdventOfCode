#include <iostream>
#include <vector>
typedef unsigned long long uint64;

uint64 binpow(uint64 base, int power)
{
    uint64 result = 1;
    while(power) {
        if(power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }
    return result;
}

// https://stackoverflow.com/a/11924315
uint64 SumOfAllFactorsx10(uint64 n)
{
    uint64 z {2};
    uint64 temp {n};
    uint64 sum { };
    uint64 product {1};
    int    pow {0};
    while(z * z <= n) {
        if(!(temp % z)) {
            temp /= z;
            ++pow;
        } else {
            for(int i = 0; i <= pow; ++i) {
                sum += binpow(z, i);
            }
            product *= sum;
            pow = 0;
            sum = 0;
            ++z;
        }
    }

    if(temp > 1) {
        product *= (1 + temp);
    }
    return product * 10;
}

uint64 SumOfAllFactorsx11(uint64 n)
{
    uint64 z {2};
    uint64 temp {n};
    uint64 sum { };
    uint64 product {1};
    int    pow {0};
    while(z * z <= n && z <= 50) {
        if(!(temp % z)) {
            temp /= z;
            ++pow;
        } else {
            for(int i = 0; i <= pow; ++i) {
                sum += binpow(z, i);
            }
            product *= sum;
            pow = 0;
            sum = 0;
            ++z;
        }
    }

    if(temp > 1) {
        product *= (1 + temp);
    }
    return product * 11;
}

int main( )
{
    uint64 input = 33100000;
    int    i     = 1;
    while(SumOfAllFactorsx10(i) <= input) {
        ++i;
    }
    std::cout << i;
}
