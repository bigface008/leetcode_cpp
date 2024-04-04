//
// Created by 汪喆昊 on 2024/3/28.
//

#include "leetcode_utils.hpp"

using namespace std;

// Input: [12, 13] or [[12, 13], [13, 14]]
// Output: {12, 13} or {{12, 13}}, {13, 14}}
string replaceBrace(string input) {
    replace(input.begin(), input.end(), '[', '{');
    replace(input.begin(), input.end(), ']', '}');
    return input;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fmt::println("Error: No input string.");
        return -1;
    }
    string input(argv[1]);
    fmt::println("{}", replaceBrace(input));
}