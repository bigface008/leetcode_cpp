//
// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int balancedString(string s) {
        const int N = s.size();
        vector<int> letterCnts(4, 0);
        for (char ch : s) {
            letterCnts[letterIdx(ch)]++;
        }
        if (allSame(letterCnts)) {
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            letterCnts[i] -= N / 4;
            if (letterCnts[i] < 0) {
                letterCnts[i] = 0;
            }
        }
        int left = 0;
        int ans = N;
        vector<int> windowLetterCnts(4, 0);
        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            windowLetterCnts[letterIdx(ch)]++;
            vector<int> temp(4, 0);
            while (left <= right) {
                bool valid = true;
                for (int i = 0; i < 4; i++) {
                    if (letterCnts[i] == 0) {
                        continue;
                    }
                    if (windowLetterCnts[i] >= letterCnts[i]) {
                        ; // valid
                    } else {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    break;
                }
                ans = min(ans, right - left + 1);
                windowLetterCnts[letterIdx(s[left])]--;
                left++;
            }
        }
        return ans;
    }

private:
    int letterIdx(char ch) {
        switch (ch) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2;
        default:
            return 3;
        }
    }

    bool allSame(vector<int> &vec) { return (vec[0] == vec[1]) && (vec[1] == vec[2]) && (vec[2] == vec[3]); }
};


int main() {
    auto f = [](string s, int expect) {
        auto output = Solution().balancedString(s);
        leetcode_assert(output == expect, "replace_the_substring_for_balanced_string s={} expect={} output={}", s,
                        expect, output);
    };
//    f("QQWE", 1);
    f("QQQW", 2);
}
