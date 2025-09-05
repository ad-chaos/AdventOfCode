#include <array>
#include <bitset>
#include <fstream>
#include <iostream>

typedef unsigned long long uint_64;
#define LIGHT_ROWS    100
#define LIGHT_COLUMNS 100
typedef std::array<std::bitset<LIGHT_COLUMNS + 2>, LIGHT_ROWS + 2> santa_lights;

void change_light_state(int& row, int& column, santa_lights& current_lights,
                        santa_lights& next_lights)
{
    int lights_on {0};
    for(int i = row - 1; i <= row + 1; ++i) {
        for(int j = column - 1; j <= column + 1; ++j) {
            if(i != row || j != column) {
                if(current_lights[i][j]) {
                    ++lights_on;
                }
            }
        }
    }
    if(current_lights[row][column] && (lights_on == 2 || lights_on == 3)) {
        next_lights[row][column] = 1;
    } else if(!current_lights[row][column] && (lights_on == 3)) {
        next_lights[row][column] = 1;
    } else {
        next_lights[row][column] = 0;
    }
}

void print_lights(santa_lights& lights)
{
    for(int i = 1; i <= LIGHT_ROWS; ++i) {
        for(int j = 1; j <= LIGHT_COLUMNS; ++j) {
            if(lights[i][j]) {
                std::cout << '#';
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main( )
{
    std::ifstream file("./input18.txt");
    char          state;
    santa_lights  lights1 {0}, lights2 {0};
    for(int i = 1; i <= LIGHT_ROWS; ++i) {
        for(int j = 1; j <= LIGHT_COLUMNS; ++j) {
            file.get(state);
            if(state == '#') {
                lights1[i][j] = 1;
                lights2[i][j] = 1;
            } else if(state == '.') {
                lights1[i][j] = 0;
                lights2[i][j] = 0;
            }
        }
    }
    lights1[1][LIGHT_COLUMNS]          = 1;
    lights1[LIGHT_ROWS][1]             = 1;
    lights1[1][1]                      = 1;
    lights1[LIGHT_ROWS][LIGHT_COLUMNS] = 1;

    lights2[1][LIGHT_COLUMNS]          = 1;
    lights2[LIGHT_ROWS][1]             = 1;
    lights2[1][1]                      = 1;
    lights2[LIGHT_ROWS][LIGHT_COLUMNS] = 1;

    int           num_loops {100};
    santa_lights *curr, *next;
    while(num_loops--) {
        if(num_loops % 2) {
            curr = &lights1;
            next = &lights2;
        } else {
            curr = &lights2;
            next = &lights1;
        }
        for(int i = 1; i <= LIGHT_ROWS; ++i) {
            for(int j = 1; j <= LIGHT_COLUMNS; ++j) {
                change_light_state(i, j, *curr, *next);
            }
        }

        (*next)[1][LIGHT_COLUMNS]          = 1;
        (*next)[LIGHT_ROWS][1]             = 1;
        (*next)[1][1]                      = 1;
        (*next)[LIGHT_ROWS][LIGHT_COLUMNS] = 1;
        //print_lights(*next);
    }

    uint_64 final_ans { };
    for(int i = 1; i <= LIGHT_ROWS; ++i) {
        for(int j = 1; j <= LIGHT_COLUMNS; ++j) {
            final_ans += (*next)[i][j];
        }
    }
    std::cout << final_ans << "\n";
}
