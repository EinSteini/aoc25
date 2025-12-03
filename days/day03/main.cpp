#include "../../aoc/input.h"
#include <cstdio>
#include <regex>

using namespace std;

int main() {
    auto lines = aoc::read_lines();
    
    unsigned long long sum = 0;
    const int digit_count = 12; // use "2" here for part 1 solution
    for(auto& line: lines){
        if(line.size() < digit_count)
            continue;
        int index = -1;
        for(int digit = 1; digit <= digit_count; ++digit){
            char max = '0';
            for(int i = index + 1; i < line.size() + digit - digit_count; ++i){
                if(line[i] > max){
                    max = line[i];
                    index = i;
                }
            }
            sum += (max - '0') * pow(10, digit_count - digit);
        }
    }

    cout << sum << endl;
    return 0;
}