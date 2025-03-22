//
// https://leetcode.cn/problems/row-with-maximum-ones/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        const int M = mat.size(), N = mat[0].size();
        int idx = -1;
        int cnt = -1;
        for (int i = 0; i < M; i++) {
            int currCnt = 0;
            for (int j = 0; j < N; j++) {
                if (mat[i][j] == 1) {
                    currCnt++;
                }
            }
            if (currCnt > cnt) {
                cnt = currCnt;
                idx = i;
            }
        }
        return {idx, cnt};
    }
};


int main() {
    auto f = [](vector<vector<int>>&& mat, vector<int> expect) {
        auto output = Solution().rowAndMaximumOnes(mat);
        leetcode_assert(output == expect, "row_with_maximum_ones mat={} expect={} output={}", mat, expect, output);
    };
    f();
}
