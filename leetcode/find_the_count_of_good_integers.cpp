//
// https://leetcode.cn/problems/find-the-count-of-good-integers/?envType=daily-question&envId=2025-04-12
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> factorial(11);
int init = []() {
    factorial[0] = 1;
    for (int i = 1; i <= 10; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    return 0;
}();


class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long start = pow(10, n - 1);
        if (start % k != 0) {
            start = (start / k + 1) * k;
        }
        long long end = (long long)pow(10, n) - 1;
        if (end % k != 0) {
            end = (end / k) * k;
        }
        unordered_set<string> palindrome_set;
        long long ans = 0;
        long long base = pow(10, (n - 1) / 2);
        for (long long i = base; i < base * 10; i++) {
            string s = to_string(i);
            s += string(s.rbegin() + (n % 2), s.rend());
            if (stoll(s) % k != 0) {
                continue;
            }
            sort(s.begin(), s.end());
            if (!palindrome_set.insert(s).second) {
                continue;
            }
            int cnt0 = 0;
            unordered_map<int, int> freq_mp;
            for (char ch : s) {
                if (ch == '0') {
                    cnt0++;
                }
                freq_mp[ch - '0']++;
            }
            long long res = (n - cnt0) * factorial[n - 1];
            for (auto [num, freq] : freq_mp) {
                res /= factorial[freq];
            }
            ans += res;
        }
        return ans;
    }
};


int main() {
    auto f = [](int n, int k, long long expect) {
        auto output = Solution().countGoodIntegers(n, k);
        leetcode_assert(output == expect, "find_the_count_of_good_integers n={} k={} expect={} output={}", n, k, expect,
                        output);
    };
    f(3, 5, 27);
}
