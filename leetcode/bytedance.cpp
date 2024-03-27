//
// Created by 汪喆昊 on 2024/3/27.
//

#include "leetcode_utils.hpp"

using namespace std;

// I think this problem can be solved by using a stack that contains pairs of integer and string.
// At first, we can push a new pair containing an integer 1 and an empty string into the stack.
// Next, iterate through the input string.
// If a number is encountered, we can push a new pair into the stack, which contains the number and a new empty string.
// If a letter is encountered, we can append the letter to the string of the top pair of the stack.
// If a closing brace is encountered, we can pop the top pair, getting the repeated string. And then we added repeat
// string into the new top pair.
// The stack will never be empty, since we've already pushed a new pair at the start of the algorithm.

string convert(string input) {
    stack<pair<int, string>> stk;
    stk.emplace(1, "");
    int i = 0;
    const int LEN = input.size();
    while (i < LEN) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            int j = i + 1;
            for (; j < LEN; j++) {
                if (input[j] == '{') {
                    break;
                }
            }
            string num_s = input.substr(i, j - i);
            int num = stoi(num_s);
            stk.emplace(num, "");
            i = j + 1;
        } else if (c >= 'a' && c <= 'z') {
            auto &&[num, str] = stk.top();
            str.push_back(c);
            i++;
        } else if (c == '}') {
            auto [num, str] = stk.top();
            stk.pop();
            string repeated_str;
            for (int j = 0; j < num; j++) {
                repeated_str.append(str);
            }
            stk.top().second.append(repeated_str);
            i++;
        }
    }
    return stk.top().second;
}

int main() {
    auto f = [](string &&input, string &&expect) {
        auto output = convert(input);
        leetcode_assert(output == expect, "bd string convert input {} output {} expect {}", input, output, expect);
    };

    f("a2{cb}dd3{ef}gg", "acbcbddefefefgg");
    f("a2{cb3{dd}ef}gg", "acbddddddefcbddddddefgg");
}
