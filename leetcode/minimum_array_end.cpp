//
// https://leetcode.com/problems/minimum-array-end/description/?envType=daily-question&envId=2024-11-09
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) {
            return x;
        }
        long long ans = x;
        int digit_len = 32 - __builtin_clz(x);
        int digit_pos = 0;
        int fill = n - 1;
        int fill_len = 32 - __builtin_clz(fill);
        int fill_pos = 0;
        while (fill_pos < fill_len) {
            while (((1LL << digit_pos) & x) != 0) {
                digit_pos++;
            }
            if (((1 << fill_pos) & fill) != 0) {
                ans += 1LL << digit_pos;
            }
            fill_pos++;
            digit_pos++;
        }
        return ans;
    }
};

int main() {
    auto f = [](int n, int x, long expect) {
        auto output = Solution().minEnd(n, x);
        leetcode_assert(output == expect, "minimum_array_end n={} x={} expect={} output={}", n, x, expect, output);
    };
    f(3, 4, 6);
}
