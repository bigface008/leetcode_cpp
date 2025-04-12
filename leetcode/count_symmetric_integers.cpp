//
// https://leetcode.cn/problems/count-symmetric-integers/?envType=daily-question&envId=2025-04-11
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int size = s.size();
            if (size % 2 != 0) {
                continue;
            }
            bool valid = true;
            int pre_sum = 0;
            int suf_sum = 0;
            for (int j = 0; j < size / 2; j++) {
                pre_sum += s[j] - '0';
                suf_sum += s[size - 1 - j] - '0';
            }
            if (pre_sum == suf_sum) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](int low, int high, int expect) {
        auto output = Solution().countSymmetricIntegers(low, high);
        leetcode_assert(output == expect, "count_symmetric_integers low={} high={} expect={} output={}", low, high, expect, output);
    };
    f();
}
