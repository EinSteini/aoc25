#include "../../aoc/input.h"
#include <cstdio>
#include <utility>

using namespace std;

bool hasValidRanges(const vector<pair<long long, long long>>& input){
    for(auto range: input){
        if(range.first != LONG_LONG_MAX || range.second != LONG_LONG_MIN) return true;
    }
    return false;
}

int main() {
    auto lines = aoc::read_lines();
    auto blocks = aoc::blocks(lines);
    if(blocks.size() != 2){
        cout << "not 2 blocks" << endl;
        return 0;
    }

    vector<pair<long long, long long>> ranges;
    ranges.reserve(blocks[0].size());
    for(auto range : blocks[0]){
        auto split = aoc::split(range, '-');
        if(split.size() != 2)
            continue;
        ranges.push_back(make_pair(stoll(split[0]), stoll(split[1])));
    }

    unsigned long long sum = 0;

    vector<pair<long long, long long>> merged_ranges;
    do{
        bool merged_something = false;
        int lowest_index = 0;
        do{
            merged_something = false;
            lowest_index = 0;
            // step 1: find pair with lowest lower bound
            for(int i = 1; i < ranges.size(); ++i){
                if(ranges[i].first == LONG_LONG_MAX) continue;
                if(ranges[i].first < ranges[lowest_index].first){
                    lowest_index = i;
                }
            }
            // step 2: find all ranges with firsts lower than the second with the lowest first
            vector<int> to_be_merged;
            for(int i = 0; i < ranges.size(); ++i){
                if(ranges[i].first <= ranges[lowest_index].second && i != lowest_index){
                    merged_something = true;
                    to_be_merged.push_back(i);
                }
            }
            // step 3: extend lowest range to highest overlapping second (and invalidate)
            for(auto index : to_be_merged){
                if(ranges[index].second > ranges[lowest_index].second){
                    ranges[lowest_index].second = ranges[index].second;
                }
                ranges[index] = make_pair(LONG_LONG_MAX, LONG_LONG_MIN);
            }
        }while(merged_something);
        // step 4: push merged pair to vector and invalidate original
        merged_ranges.push_back(ranges[lowest_index]);
        ranges[lowest_index] = make_pair(LONG_LONG_MAX, LONG_LONG_MIN);
    }while(hasValidRanges(ranges));
    

    for(auto range: merged_ranges){
        cout << range.first << "-" << range.second << endl;
        sum += range.second - range.first + 1;
    }

    cout << sum << endl;
    return 0;
}


int main_part1() {
    auto lines = aoc::read_lines();
    auto blocks = aoc::blocks(lines);
    if(blocks.size() != 2){
        cout << "not 2 blocks" << endl;
        return 0;
    }

    vector<pair<long long, long long>> ranges;
    ranges.reserve(blocks[0].size());
    for(auto range : blocks[0]){
        auto split = aoc::split(range, '-');
        if(split.size() != 2)
            continue;
        ranges.push_back(make_pair(stoll(split[0]), stoll(split[1])));
    }
    const auto ids = aoc::to_numbers<long long>(blocks[1]);

    unsigned long long sum = 0;

    for(auto id : ids){
        for(auto range : ranges){
            if(id >= range.first && id <= range.second){
                ++sum;
                break;
            }
        }
    }

    cout << sum << endl;
    return 0;
}