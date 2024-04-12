//
// https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

string decodeString(string s) {
    stack<pair<int, string>> stk;
    stk.emplace(1, "");
    int i = 0;
    while (i < s.size()) {
        if (isdigit(s[i])) {
            int j = i + 1;
            for (; j < s.size(); j++) {
                if (s[j] == '[') {
                    break;
                }
            }
            string num_str = s.substr(i, j - i);
            int num = stoi(num_str);
            stk.emplace(num, "");
            i = j + 1;
        } else if (islower(s[i])) {
            stk.top().second.push_back(s[i]);
            i++;
        } else if (s[i] == ']') {
            auto [cnt, str] = stk.top();
            stk.pop();
            for (int j = 0; j < cnt; j++) {
                stk.top().second.append(str);
            }
            i++;
        }
    }
    return stk.top().second;
}

int main() {
    auto f = [](string &&s, string &&expect) {
        auto output = decodeString(s);
        leetcode_assert(output == expect, "decode_string s={} expect={} output={}", s, expect, output);
    };
    f("3[a]2[bc]", "aaabcbc");
    f("3[a2[c]]", "accaccacc");
    f("2[abc]3[cd]ef", "abcabccdcdcdef");
}
