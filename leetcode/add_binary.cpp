//
// Created by 汪喆昊 on 2024/3/27.
//

#include "leetcode_utils.hpp"

using namespace std;

// https://leetcode.com/problems/add-binary/?envType=study-plan-v2&envId=top-interview-150
//
// The solution to this problem should be to simply traverse both strings, using an integer value to represent carry,
// say, 'carry', and another integer to represent the index. At the beginning of each iteration, check if the current
// index is out of range in the input string. If it is within range, add its value to 'carry'. Then, check if 'carry' is
// greater than 2. If it is, set the carry for the next iteration to 1.

string addBinary(string a, string b) {
    int carry = 0;
    int i = 0;
    string res;
    while (true) {
        int temp = carry;
        if (i < a.size()) {
            temp += a[a.size() - i - 1] - '0';
        }
        if (i < b.size()) {
            temp += b[b.size() - i - 1] - '0';
        }
        if (temp >= 2) {
            temp -= 2;
            carry = 1;
        } else {
            carry = 0;
        }
        res.insert(res.begin(), '0' + temp);
        i++;
        if (carry == 0) {
            if (i >= a.size() && i >= b.size()) {
                break;
            }
        }
    }
    return res;
}

int main() {
    auto f = [](string &&a, string &&b, string &&expect) {
        auto output = addBinary(a, b);
        leetcode_assert(output == expect, "add binary a {} b {} output {} expect {}", a, b, output, expect);
    };

    f("11", "1", "100");
    f("1010", "1011", "10101");
}
