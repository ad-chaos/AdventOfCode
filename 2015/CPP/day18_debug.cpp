#include <array>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

#define LIGHT_ROWS    6
#define LIGHT_COLUMNS 6
#define santa_lights  std::array<std::bitset<LIGHT_COLUMNS>, LIGHT_ROWS>
//#define santa_lights  std::vector<std::vector<bool>>

void change_light_state(int& row,int& column, santa_lights& current_lights,
                        santa_lights& next_lights)
{
    int lights_on {0};

    //look at neighbouring lights centered at row,column
    for(int i = row - 1; i <= row+1; ++i) {
        for(int j = column - 1; j <= column+1; ++j) {
            if(i >= 0 && j >= 0 && i != row && j != column) {
                if(current_lights[i][j]) {
                    ++lights_on;
                }
            }
        }
    }

    if(!current_lights[row][column] && lights_on == 3) {
        next_lights[row][column] = 1;
    } else if(current_lights[row][column] &&
              (lights_on == 3 || lights_on == 2)) {
        next_lights[row][column] = 1;
    } else {
        next_lights[row][column] = 0;
    }
}

void print_answer(santa_lights& lights) {
    int final_answer {};
    for(int i = 0; i < LIGHT_ROWS; ++i) {
        for(int j = 0; j < LIGHT_COLUMNS; ++j) {
            if(lights[i][j]) {
                std::cout << "#";
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main()
{
    std::ifstream file("./input18.txt");
    char          state {};
    santa_lights  lights, lights_prev;
    for(int i = 0; i < LIGHT_ROWS; ++i) {
        for(int j = 0; j < LIGHT_COLUMNS; ++j) {
            if(state == '#') {
                lights[i][j]      = 1;
                lights_prev[i][j] = 1;
            } else if(state == '.') {
                lights[i][j]      = 0;
                lights_prev[i][j] = 0;
            }
        }
    }
    print_answer(lights);

    santa_lights *curr, *next;
    for(int num_loop = 0; num_loop < 5; ++num_loop) {
        if(!(num_loop % 2)) {
            curr = &lights;
            next = &lights_prev;
        } else {
            curr = &lights_prev;
            next = &lights;
        }
        print_answer(*next);
        for(int i = 0; i < LIGHT_ROWS; ++i) {
            for(int j = 0; j < LIGHT_COLUMNS; ++j) {
                change_light_state(j, i, *curr, *next);
            }
        }
    }
}
