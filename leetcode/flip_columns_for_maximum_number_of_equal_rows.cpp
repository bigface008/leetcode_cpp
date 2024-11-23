//
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/?envType=daily-question&envId=2024-11-22
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        const int M = matrix.size(), N = matrix[0].size();
        int ans = 0;
        unordered_map<string, int> cnt;
        for (auto &row : matrix) {
            string r(N, 0);
            for (int j = 0; j < N; j++) {
                r[j] = row[j] ^ row[0];
            }
            ans = max(ans, ++cnt[r]);
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<vector<int>>&& matrix, int expect) {
        auto output = Solution().maxEqualRowsAfterFlips(matrix);
        leetcode_assert(output == expect, "flip_columns_for_maximum_number_of_equal_rows matrix={} expect={} output={}", matrix, expect, output);
    };
    f();
}
