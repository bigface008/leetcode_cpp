//
// https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/description/?envType=daily-question&envId=2024-11-22
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int vl = sqrt(l);
        int ans = r - l + 1;
        for (int i = vl; i * i <= r; i++) {
            int p = i * i;
            if (p >= l && p <= r && isPrime(i)) {
                ans--;
            }
        }
        return ans;
    }

private:
    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    auto f = [](int l, int r, int expect) {
        auto output = Solution().nonSpecialCount(l, r);
        leetcode_assert(output == expect, "find_the_count_of_numbers_which_are_not_special l={} r={} expect={} output={}", l, r, expect, output);
    };
    f();
}
