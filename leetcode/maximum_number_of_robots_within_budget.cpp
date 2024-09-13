//
// https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        int N = chargeTimes.size();
        int left = 0;
        long long runCostSum = 0;
        int windowSize = 0;
        deque<int> chargeTimeStk;
        int ans = 0;
        for (int right = 0; right < N; right++) {
            int time = chargeTimes[right];
            int cost = runningCosts[right];
            while (!chargeTimeStk.empty() && chargeTimes[chargeTimeStk.back()] <= time) {
                chargeTimeStk.pop_back();
            }
            chargeTimeStk.push_back(right);
            windowSize += 1;
            runCostSum += cost;
            while (windowSize > 0 && !chargeTimeStk.empty() && runCostSum * windowSize + chargeTimes[chargeTimeStk[0]] > budget) {
                if (chargeTimeStk.front() == left) {
                    chargeTimeStk.pop_front();
                }
                runCostSum -= runningCosts[left];
                windowSize--;
                left++;
            }
            ans = max(ans, windowSize);
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<int> &&chargeTimes, vector<int> &&runningCosts, long long budget, int expect) {
        auto output = Solution().maximumRobots(chargeTimes, runningCosts, budget);
        leetcode_assert(
            output == expect,
            "maximum_number_of_robots_within_budget chargeTimes={} runningCosts={} long={} expect={} output={}",
            chargeTimes, runningCosts, budget, expect, output);
    };
    f({11, 12, 74, 67, 37, 87, 42, 34, 18, 90, 36, 28, 34, 20}, {18, 98, 2, 84, 7, 57, 54, 65, 59, 91, 7, 23, 94, 20},
      937, 0);
};
