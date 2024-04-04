//
// Created by 汪喆昊 on 2024/3/29.
// https://leetcode.com/problems/generate-parentheses/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

void backtrack(int open, int close, string &temp, vector<string> &res) {
    if (open == 0 && close == 0) {
        res.push_back(temp);
        return;
    }
    if (open == close) {
        string str(temp);
        str.push_back('(');
        backtrack(open - 1, close, str, res);
    } else {
        if (open == 0) {
            string str(temp);
            str.push_back(')');
            backtrack(0, close - 1, str, res);
        } else if (close == 0) {
            string str(temp);
            str.push_back('(');
            backtrack(open - 1, 0, str, res);
        } else {
            string str1(temp), str2(temp);
            str1.push_back('(');
            backtrack(open - 1, close, str1, res);
            str2.push_back(')');
            backtrack(open, close - 1, str2, res);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp;
    backtrack(n, n, temp, res);
    return res;
}

int main() {
    auto f = [](int n, vector<string> &&expect) {
        auto output = generateParenthesis(n);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "generate parenthesis n={} expect={} output={}", n, expect, output);
    };
    f(3, {"((()))", "(()())", "(())()", "()(())", "()()()"});
    f(1, {"()"});
}
