//
// https://leetcode.cn/problems/count-good-numbers/?envType=daily-question&envId=2025-04-13
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        return qpow(5, (n + 1) / 2) * qpow(4, n / 2) % MOD;
    }

private:
    const long long MOD = 1e9 + 7;

    long long qpow(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
};


int main() {
    auto f = [](long long n, int expect) {
        Solution solution;
        auto output = solution.countGoodNumbers(n);
        leetcode_assert(output == expect, "count_good_numbers n={} expect={} output={}", n, expect, output);
    };
    f(1, 5);
}
