//
// https://leetcode.com/problems/removing-stars-from-a-string/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

string removeStars(string s) {
    int start_i = 0;
    string res = "";
    for (char c : s) {
        if (c == '*') {
            res.pop_back();
        } else {
            res.push_back(c);
        }
    }
    return res;
}

int main() {
    auto f = [](string &&s, string &&expect) {
        auto output = removeStars(s);
        leetcode_assert(output == expect, "removing_stars_from_a_string s={} expect={} output={}", s, expect, output);
    };
    f("leet**cod*e", "lecoe");
    f("erase*****", "");
}
