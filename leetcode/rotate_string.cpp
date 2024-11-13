//
// https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-03
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        const int N = s.size();
        if (goal.size() != N) {
            return false;
        }
        for (int i = 0; i < N; i++) {
            if (s[i] == goal[0]) {
                bool valid = true;
                for (int k = 1; k < N; k++) {
                    int k1 = (i + k) % N;
                    int k2 = k % N;
                    if (s[k1] != goal[k2]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    return true;
                }
           }
        }
        return false;
    }
};

int main() {
    auto f = [](string &&s, string &&goal, bool expect) {
        auto output = Solution().rotateString(s, goal);
        leetcode_assert(output == expect, "rotate_string s={} goal={} expect={} output={}", s, goal, expect, output);
    };
//    f("abcde", "cdeab", true);
    f("defdefdefabcabc", "defdefabcabcdef", true);
}
