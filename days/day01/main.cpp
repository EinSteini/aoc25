#include "../../aoc/input.h"
#include <cstdio>

using namespace std;

int main() {

    auto lines = aoc::read_lines();
    
    int zeroes = 0;
    int state = 50;
    for(const string& line : lines) {
        if(line.empty())
            continue;

        const char rotation = line[0];
        const int turns = stoi(line.substr(1, line.size()));
        if(turns == 0)
            continue;

        if (rotation == 'L') {
            if(state <= turns % 100 && state != 0)
                ++zeroes;
            state -= turns;
        } else if(rotation == 'R') {
            if((100 - state) <= turns % 100)
                ++zeroes;
            state += turns;
        } else {
            continue;
        }
        zeroes += turns / 100;

        state = state % 100;
        if(state < 0)
            state += 100;
    }

    cout << zeroes << endl;
    return 0;
}


int main_part1(){
    auto lines = aoc::read_lines();
    
    int zeros = 0;
    int state = 50;
    for(const string& line : lines) {
        if(line.empty())
            continue;

        const char rotation = line.at(0);
        const int turns = stoi(line.substr(1, line.size()));

        if(rotation == 'L'){
            state -= turns;
        }else if(rotation == 'R'){
            state += turns;
        }else{
            continue;
        }

        state = state % 100;
        if(state == 0){
            ++zeros;
        }
    }

    cout << zeros << endl;
    return 0;
}