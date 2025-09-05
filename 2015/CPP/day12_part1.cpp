#include <fstream>
#include <iostream>
#include <string>

#define NUMBER_ZERO   47
#define NUMBER_NINE   57
#define MINUS_SIGN    45
#define OPENING_BRACE 123
#define CLOSING_BRACE 125

bool is_number(int&& casted_byte)
{
    return (NUMBER_ZERO <= casted_byte && casted_byte <= NUMBER_NINE) ||
           casted_byte == MINUS_SIGN;
}

int main()
{
    std::ifstream fopen("input12.txt");
    char          byte;
    std::string   reading("");
    int           total {0};

    while(fopen.get(byte)) {
        if(is_number((int)byte)) {
            reading += byte;
        } else if(reading.length()) {
            total += std::stoi(reading);
            reading.clear();
        }
    }
    std::cout << total << "\n";
}
