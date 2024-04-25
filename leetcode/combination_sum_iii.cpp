//
// https://leetcode.com/problems/combination-sum-iii/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

vector<vector<int>> combinationSum3(int k, int n) {

}

int main() {
    auto f = [](int k, int n, vector<vector<int>> &&expect) {
        auto output = combinationSum3(k, n);
        leetcode_assert(output == expect, "combination_sum_iii k={} n={} expect={} output={}", k, n, expect, output);
    };
    f(3, 7, {{1, 2, 4}});
    f(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});
    f(4, 1, {});
    vector<int> v;
}
