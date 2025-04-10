//
// https://leetcode.cn/problems/count-the-number-of-powerful-integers/?envType=daily-question&envId=2025-04-10
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        low = to_string(start);
        high = to_string(finish);
        N = high.size();
        diff = N - s.size();
        low = string(N - low.size(), '0') + low;
        this->s = s;
        this->limit = limit;

        return dfs(0, true, true);
    }

private:
    int N;
    int diff;
    int limit;
    string high;
    string low;
    string s;

    unordered_map<int, unordered_map<bool, unordered_map<bool, long long>>> cache;

    long long dfs(int i, bool limitLow, bool limitHigh) {
        if (cache.contains(i) && cache[i].contains(limitHigh) && cache[i][limitHigh].contains(limitLow)) {
            return cache[i][limitHigh][limitLow];
        }
        long long res = 0;
        if (i == N) {
            res = 1;
        } else {
            int lo = limitLow ? (low[i] - '0') : 0;
            int hi = limitHigh ? (high[i] - '0') : 9;
            res = 0;
            if (i < diff) {
                for (int d = lo; d <= min(hi, limit); d++) {
                    res += dfs(i + 1, limitLow && d == lo, limitHigh && d == hi);
                }
            } else {
                int x = s[i - diff] - '0';
                if (lo <= x && x <= min(hi, limit)) {
                    res = dfs(i + 1, limitLow && x == lo, limitHigh && x == hi);
                }
            }
        }
        cache[i][limitHigh][limitLow] = res;
        return res;
    }
};


int main() {
    auto f = [](long long start, long long finish, int limit, string s, long long expect) {
        auto output = Solution().numberOfPowerfulInt(start, finish, limit, s);
        leetcode_assert(output == expect,
                        "count_the_number_of_powerful_integers start={} finish={} limit={} s={} expect={} output={}",
                        start, finish, limit, s, expect, output);
    };
    f(1, 6000, 4, "124", 5);
}
