//
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int N = candies.size();
        vector<bool> ans(N, false);
        int maxIdx = max_element(candies.begin(), candies.end()) - candies.begin();
        int maxVal = candies[maxIdx];
        for (int i = 0; i < N; i++) {
            bool res = false;
            if (i == maxIdx) {
                res = true;
            } else {
                res = candies[i] + extraCandies >= maxVal;
            }
            ans[i] = res;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& candies, int extraCandies, vector<bool> expect) {
        auto output = Solution().kidsWithCandies(candies, extraCandies);
        leetcode_assert(output == expect, "kids_with_the_greatest_number_of_candies candies={} extraCandies={} expect={} output={}", candies, extraCandies, expect, output);
    };
    f();
}
