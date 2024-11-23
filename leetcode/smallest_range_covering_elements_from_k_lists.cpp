//
// https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/?envType=daily-question&envId=2024-11-24
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    typedef tuple<int, int, int> Info;

    vector<int> smallestRange(vector<vector<int>> &nums) {
        const int K = nums.size();
        priority_queue<Info, vector<Info>, greater<>> pq;
        int maxVal = INT_MIN;
        for (int i = 0; i < K; i++) {
            int x = nums[i][0];
            pq.emplace(x, i, 0);
            maxVal = max(maxVal, x);
        }
        int left = 0, right = INT_MAX;
        while (pq.size() == K) {
            auto [val, arrIdx, valIdx] = pq.top();
            pq.pop();
            if (maxVal - val < right - left || (maxVal - val == right - left && val < left)) {
                left = val;
                right = maxVal;
            }
            if (valIdx + 1 < nums[arrIdx].size()) {
                int x = nums[arrIdx][valIdx + 1];
                pq.emplace(x, arrIdx, valIdx + 1);
                maxVal = max(maxVal, x);
            }
        }
        return {left, right};
    }
};


int main() {
    auto f = [](vector<vector<int>> &&nums, vector<int> expect) {
        auto output = Solution().smallestRange(nums);
        leetcode_assert(output == expect, "smallest_range_covering_elements_from_k_lists nums={} expect={} output={}",
                        nums, expect, output);
    };
    f(make2DIntVecByStr("[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]"), {20, 24});
}
