//
// Created by 汪喆昊 on 2024/3/28.
//

#include "leetcode_utils.hpp"

using namespace std;


void backtrack(int idx, const vector<string> &dict, string &digits, string &temp, vector<string> &res) {
    if (idx == digits.size()) {
        res.push_back(temp);
        return;
    }
    string katta = dict[digits[idx] - '0' - 1];
    for (char c : katta) {
        temp.push_back(c);
        backtrack(idx + 1, dict, digits, temp, res);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
        return {};
    }
    const vector<string> dict{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", ""};
    vector<string> res;
    string temp;
    backtrack(0, dict, digits, temp, res);
    return res;
}

int main() {
    auto f = [](string &&digits, vector<string> &&expect) {
        auto output = letterCombinations(digits);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "letter combination digits={} expect={} output={}", digits, expect, output);
    };

    f("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    f("", {});
    f("2", {"a", "b", "c"});
}
