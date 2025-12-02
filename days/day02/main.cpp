#include "../../aoc/input.h"
#include <cstdio>
#include <regex>

using namespace std;

int main() {
    auto lines = aoc::read_lines();
    
    unsigned long long sum = 0;
    for(auto& line: lines){
        auto ranges = aoc::split(line, ',');
        for(auto& range: ranges){
            if(range.empty())
                continue;
            auto split_range = aoc::split(range, '-');
            if(split_range.size() != 2)
                continue;
            const unsigned long long start = stol(split_range[0]);
            const unsigned long long end = stol(split_range[1]);
            for(unsigned long long i = start; i <= end; ++i){
                string number = to_string(i);
                regex find_duplicates("^(\\d+)(\\1)+$", regex_constants::ECMAScript);
                if(regex_search(number, find_duplicates)){
                    sum += i;
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}

int main_part1(){
    auto lines = aoc::read_lines();
    
    unsigned long long sum = 0;
    for(auto& line: lines){
        auto ranges = aoc::split(line, ',');
        for(auto& range: ranges){
            if(range.empty())
                continue;
            auto split_range = aoc::split(range, '-');
            if(split_range.size() != 2)
                continue;
            const unsigned long long start = stol(split_range[0]);
            const unsigned long long end = stol(split_range[1]);
            for(unsigned long long i = start; i <= end; ++i){
                string number = to_string(i);
                regex find_duplicates("^(\\d+)(\\1)$", regex_constants::ECMAScript);
                if(regex_search(number, find_duplicates)){
                    sum += i;
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}