//
// https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        const int M = box.size(), N = box[0].size();
        vector<vector<char>> ans(N, vector<char>(M, '.'));
        for (int i = 0; i < M; i++) {
            int stoneCnt = 0;
            int obstaclePos = N;
            for (int j = N - 1; j >= 0; j--) {
                char ch = box[i][j];
                if (ch == '*') {
                    ans[j][M - 1 - i] = '*';
                    for (int k = 0; k < stoneCnt; k++) {
                        ans[obstaclePos - 1 - k][M - 1 - i] = '#';
                    }
                    stoneCnt = 0;
                    obstaclePos = j;
                } else if (ch == '#') {
                    stoneCnt++;
                }
            }
            for (int k = 0; k < stoneCnt; k++) {
                ans[obstaclePos - 1 - k][M - 1 - i] = '#';
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<vector<char>> &&box, vector<vector<char>> expect) {
        auto output = Solution().rotateTheBox(box);
        leetcode_assert(output == expect, "rotating_the_box box={} expect={} output={}", box, expect, output);
    };
//    f({{'#', '.', '#'}}, {{'.'}, {'#'}, {'#'}});
    f({{'#', '.', '*', '.'}, {'#', '#', '*', '.'}}, {{'#', '.'}, {'#', '#'}, {'*', '*'}, {'.', '.'}});
}
