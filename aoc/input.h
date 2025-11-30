#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

namespace aoc {

    vector<string> read_lines() {
        vector<string> lines;
        string s;
        while (getline(cin, s))
            lines.push_back(s);
        return lines;
    }

    vector<vector<string>> blocks(const vector<string>& lines) {
        vector<vector<string>> out;
        vector<string> curr;
        for (auto& l : lines) {
            if (l.empty()) {
                out.push_back(curr);
                curr.clear();
            } else {
                curr.push_back(l);
            }
        }
        if (!curr.empty()) out.push_back(curr);
        return out;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> out;
        string item;
        stringstream ss(s);
        while (getline(ss, item, delim))
            out.push_back(item);
        return out;
    }

    vector<string> split_ws(const string& s) {
        stringstream ss(s);
        vector<string> out;
        string t;
        while (ss >> t)
            out.push_back(t);
        return out;
    }

    template<typename T>
    vector<T> to_numbers(const vector<string>& vs) {
        vector<T> out;
        for (auto& x : vs) out.push_back((T)stoll(x));
        return out;
    }
}
