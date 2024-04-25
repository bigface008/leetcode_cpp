//
// https://leetcode.com/problems/daily-temperatures/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
    const int LEN = temperatures.size();
    stack<int> stk;
    vector<int> res(LEN, 0);
    for (int i = 0; i < LEN; i++) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            res[idx] = i - idx;
        }
        stk.push(i);
    }
    return res;
}

int main() {
    auto f = [](vector<int> &&temperatures, vector<int> &&expect) {
        auto output = dailyTemperatures(temperatures);
        leetcode_assert(output == expect, "daily_temperatures temperatures={} expect={} output={}", temperatures,
                        expect, output);
    };
    f({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0});
    f({30, 40, 50, 60}, {1, 1, 1, 0});
    f({30, 60, 90}, {1, 1, 0});
}
