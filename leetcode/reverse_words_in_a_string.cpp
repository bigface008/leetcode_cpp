//
// https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

string reverseWords(string s) {
    vector<string> res;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        int j = i;
        for (; j < s.size(); j++) {
            if (s[j] == ' ') {
                break;
            }
        }
        string temp = s.substr(i, j - i);
        res.push_back(temp);
        i = j + 1;
    }
    string ans;
    for (int i = 0; i < res.size(); i++) {
        if (i != 0) {
            ans.push_back(' ');
        }
        ans.append(res[res.size() - i - 1]);
    }
    return ans;
}

int main() {
    auto f = [](string &&s, string &&expect) {
        auto output = reverseWords(s);
        leetcode_assert(output == expect, R"(reverse_words_in_a_string s="{}" expect="{}" output="{}")", s, expect, output);
    };
    f("the sky is blue", "blue is sky the");
    f("  hello world  ", "world hello");
    f("a good   example", "example good a");
}
