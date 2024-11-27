//
// https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        const int N = matrix.size();
        long long ans = 0;
        int negativeCnt = 0;
        long long sum = 0;
        int minAbs = INT_MAX;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int x = matrix[i][j];
                if (x < 0) {
                    negativeCnt++;
                }
                x = abs(x);
                sum += x;
                minAbs = min(x, minAbs);
            }
        }
        if (negativeCnt % 2 == 0) {
            return sum;
        } else {
            return sum - 2 * minAbs;
        }
    }
};


int main() {
    auto f = [](vector<vector<int>>&& matrix, long long expect) {
        auto output = Solution().maxMatrixSum(matrix);
        leetcode_assert(output == expect, "maximum_matrix_sum matrix={} expect={} output={}", matrix, expect, output);
    };
    f();
}
