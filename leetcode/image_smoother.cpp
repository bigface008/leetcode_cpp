//
// https://leetcode.cn/problems/image-smoother/description/?envType=daily-question&envId=2024-11-18
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int M = img.size(), N = img[0].size();
        vector<pair<int, int>> pos{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        vector<vector<int>> ans(M, vector<int>(N));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                int sum = 0;
                int cnt = 0;
                for (auto [dx, dy] : pos) {
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < M && 0 <= y && y < N) {
                        sum += img[x][y];
                        cnt++;
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<vector<int>>&& img, vector<vector<int>> expect) {
        auto output = Solution().imageSmoother(img);
        leetcode_assert(output == expect, "image_smoother img={} expect={} output={}", img, expect, output);
    };
    f();
}
