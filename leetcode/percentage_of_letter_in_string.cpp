//
// https://leetcode.cn/problems/percentage-of-letter-in-string/?envType=daily-question&envId=2025-03-31
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        const int N = s.size();
        int cnt = 0;
        for (char ch : s) {
            if (ch == letter) {
                cnt++;
            }
        }
        return cnt * 100 / N;
    }
};


int main() {
    auto f = [](string s, char letter, int expect) {
        auto output = Solution().percentageLetter(s, letter);
        leetcode_assert(output == expect, "percentage_of_letter_in_string s={} letter={} expect={} output={}", s, letter, expect, output);
    };
    f();
}
