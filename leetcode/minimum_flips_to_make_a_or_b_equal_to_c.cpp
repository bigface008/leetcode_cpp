//
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int minFlips(int a, int b, int c) {
    int ans = 0;
    while (c > 0 || b > 0 || a > 0) {
        int cv = c & 1;
        int av = a & 1;
        int bv = b & 1;
        int temp = av | bv;
        if (temp != cv) {
            if (temp == 0) {
                ans += 1;
            } else {
                if (av == 1) {
                    ans++;
                }
                if (bv == 1) {
                    ans++;
                }
            }
        }
        c >>= 1;
        b >>= 1;
        a >>= 1;
    }
    return ans;
}

int main() {
    auto f = [](int a, int b, int c, int expect) {
        auto output = minFlips(a, b, c);
        leetcode_assert(output == expect, "minimum_flips_to_make_a_or_b_equal_to_c a={} b={} c={} expect={} output={}", a, b, c, expect, output);
    };
    f(8, 3, 5, 3);
    f(2, 6, 5, 3);
    f(4, 2, 7, 1);
    f(1, 2, 3, 0);
}
