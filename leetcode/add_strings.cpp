//
// https://leetcode.com/problems/add-strings/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i1 = 0, i2 = 0;
        int N1 = num1.size(), N2 = num2.size();
        string ans;
        int carry = 0;
        while (i1 < N1 && i2 < N2) {
            int offset1 = N1 - i1 - 1;
            int offset2 = N2 - i2 - 1;
            int n1 = num1[offset1] - '0', n2 = num2[offset2] - '0';
            int temp = n1 + n2 + carry;
            if (temp >= 10) {
                temp -= 10;
                ans.insert(ans.begin(), temp);
                carry = 1;
            } else {
                ans.insert(ans.begin(), temp);
                carry = 0;
            }
            i1++;
            i2++;
        }
        while (i1 < N1) {
            int offset1 = N1 - i1 - 1;
            int n1 = num1[offset1] - '0';
            int temp = n1 + carry;
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
                ans.insert(ans.begin(), temp);
            } else {
                carry = 0;
                ans.insert(ans.begin(), temp);
            }
            i1++;
        }
        while (i2 < N2) {
            int offset2 = N2 - i2 - 1;
            int n2 = num2[offset2] - '0';
            int temp = n2 + carry;
            if (temp >= 10) {
                temp -= 10;
                carry = 1;
                ans.insert(ans.begin(), temp);
            } else {
                carry = 0;
                ans.insert(ans.begin(), temp);
            }
            i2++;
        }
        if (carry == 1) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};

int main() {
    auto f = [](string &&num1, string &&num2, string &&expect) {
        auto output = Solution().addStrings(num1, num2);
        leetcode_assert(output == expect, "add_strings num1={} num2={} expect={} output={}", num1, num2, expect,
                        output);
    };
//    f();
};
