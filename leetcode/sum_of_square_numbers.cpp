//
// https://leetcode.cn/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-11-04
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; i <= c / 2; i++) {
            double p = pow(i, 2);
            if (p > c) {
                break;
            }
            int remain = c - (int) p;
            int sq = sqrt(remain);
            if (pow(sq, 2) == remain) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto f = [](int c, bool expect) {
        auto output = Solution().judgeSquareSum(c);
        leetcode_assert(output == expect, "sum_of_square_numbers c={} expect={} output={}", c, expect, output);
    };
    f(11, false);
}
