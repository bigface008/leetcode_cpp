//
// https://leetcode.com/problems/greatest-common-divisor-of-strings/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 == str2 + str1) {
            return str1.substr(0, gcd(str1.size(), str2.size()));
        } else {
            return "";
        }
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }
};

class Solution2 {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) {
            swap(str1, str2);
        }
        const int N1 = str1.size(), N2 = str2.size();
        vector<int> divisors = getDivisors(gcd(N1, N2));
        int len = -1;
        for (int i = divisors.size() - 1; i >= 0; i--) {
            int div = divisors[i];
            bool valid = true;
            for (int k = 0; k < div; k++) {
                for (int j = 0; j < N2 / div - 1; j++) {
                    if (str2[j * div + k] != str2[(j + 1) * div + k]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                continue;
            }
            for (int j = 0; j < N1 / div; j++) {
                for (int k = 0; k < div; k++) {
                    if (str1[j * div + k] != str2[k]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {
                continue;
            }
            len = div;
            break;
        }
        if (len == -1) {
            return "";
        }
        return str2.substr(0, len);
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return a;
    }

    vector<int> getDivisors(int num) {
        unordered_set<int> st;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                st.insert(i);
                st.insert(num / i);
            }
        }
        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    auto f = [](string str1, string str2, string expect) {
        auto output = Solution().gcdOfStrings(str1, str2);
        leetcode_assert(output == expect, "greatest_common_divisor_of_strings str1={} str2={} expect={} output={}",
                        str1, str2, expect, output);
    };
    f("ABCABC", "ABC", "ABC");
}
