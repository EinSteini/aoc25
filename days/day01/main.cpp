#include "aoc/input.h"

using namespace std;

int main() {
    auto lines = aoc::read_lines();
    
    long long sum = 0;
    for (auto& l : lines) {
        aoc::split_ws(l);
        for(auto& num_str : aoc::split_ws(l)) {
            if(num_str.empty())
                continue;
            sum += stoll(num_str);
        }
    }

    cout << sum << endl;
}
