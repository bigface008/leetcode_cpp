//
// https://leetcode.com/problems/combination-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

const int LEN = 9;

void backtrack(int i, vector<int> &comb, int remain, const int K, vector<bool> &used, vector<vector<int>> &res) {
    remain -= i;
    if (comb.size() == K) {
        if (remain == 0) {
            res.push_back(comb);
        }
        return;
    }
    used[i - 1] = true;
    for (int j = i + 1; j <= LEN; j++) {
        if (!used[j - 1]) {
            comb.push_back(j);
            backtrack(j, comb, remain, K, used, res);
            comb.pop_back();
        }
    }
    used[i - 1] = false;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    for (int i = 1; i <= LEN; i++) {
        vector<bool> used(LEN, false);
        used[i - 1] = true;
        vector<int> comb{i};
        backtrack(i, comb, n, k, used, res);
    }
    return res;
}

int main() {
    auto f = [](int k, int n, vector<vector<int>> &&expect) {
        auto output = combinationSum3(k, n);
        leetcode_assert(output == expect, "combination_sum_iii k={} n={} expect={} output={}", k, n, expect, output);
    };
    f(3, 7, {{1, 2, 4}});
    f(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    f(4, 1, {});
    f(4, 24, make2DIntVecByStr("[[1,6,8,9],[2,5,8,9],[2,6,7,9],[3,4,8,9],[3,5,7,9],[3,6,7,8],[4,5,6,9],[4,5,7,8]]"));
}
