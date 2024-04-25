//
// https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int numTilings(int n) {
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n + 3, 0);
    const int M = 1e9 + 7;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 5;
    for (int i = 3; i < n; i++) {
        dp[i] = 2 * dp[i - 1] + dp[i - 3] % M;
    }
    return dp[n - 1];
}

int main() {
    auto f = [](int n, int expect) {
        auto output = numTilings(n);
        leetcode_assert(output == expect, "domino_and_tromino_tiling n={} expect={} output={}", n, expect, output);
    };
    f(3, 5);
    f(1, 1);
}
