#include "../../aoc/input.h"
#include <cstdio>
#include <regex>

using namespace std;

int main() {
    auto lines = aoc::read_lines();
    
    unsigned long long sum = 0;
    int run_sum = 0;
    do{
        run_sum = 0;
        for(int i = 0; i < lines.size(); ++i){
            for(int j = 0; j < lines[i].length(); ++j){
                if(lines[i][j] != '@')
                    continue;
                int ats = 0;
                if(i > 0){
                    ats += lines[i-1][j] == '@';
                    if(j > 0){
                        ats += lines[i-1][j-1] == '@';
                    }
                    if(j < lines[i].length()-1){
                        ats += lines[i-1][j+1] == '@';
                    }
                }
                if(i < lines.size()-1){
                    ats += lines[i+1][j] == '@';
                    if(j > 0){
                        ats += lines[i+1][j-1] == '@';
                    }
                    if(j < lines[i].length()-1){
                        ats += lines[i+1][j+1] == '@';
                    }
                }
                if(j > 0){
                    ats += lines[i][j-1] == '@';
                }
                if(j < lines[i].length()-1){
                    ats += lines[i][j+1] == '@';
                }
                if(ats < 4){
                    ++run_sum;
                    lines[i][j] = '.';
                }
            }
        }
        sum += run_sum;
    }while(run_sum != 0);

    cout << sum << endl;
    return 0;
}

int main_part1() {
    auto lines = aoc::read_lines();
    
    unsigned long long sum = 0;
    for(int i = 0; i < lines.size(); ++i){
        for(int j = 0; j < lines[i].length(); ++j){
            if(lines[i][j] != '@')
                continue;
            int ats = 0;
            if(i > 0){
                ats += lines[i-1][j] == '@';
                if(j > 0){
                    ats += lines[i-1][j-1] == '@';
                }
                if(j < lines[i].length()-1){
                    ats += lines[i-1][j+1] == '@';
                }
            }
            if(i < lines.size()-1){
                ats += lines[i+1][j] == '@';
                if(j > 0){
                    ats += lines[i+1][j-1] == '@';
                }
                if(j < lines[i].length()-1){
                    ats += lines[i+1][j+1] == '@';
                }
            }
            if(j > 0){
                ats += lines[i][j-1] == '@';
            }
            if(j < lines[i].length()-1){
                ats += lines[i][j+1] == '@';
            }
            sum += ats < 4;
        }
    }

    cout << sum << endl;
    return 0;
}