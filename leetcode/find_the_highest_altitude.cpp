//
// https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int altitude = 0;
        for (int i : gain) {
            altitude += i;
            ans = max(ans, altitude);
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& gain, int expect) {
        auto output = Solution().largestAltitude(gain);
        leetcode_assert(output == expect, "find_the_highest_altitude gain={} expect={} output={}", gain, expect, output);
    };
    f();
}
