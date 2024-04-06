//
// Created by 汪喆昊 on 2024/4/5.
// https://leetcode.com/problems/number-of-1-bits/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int hammingWeight(int n) {
    int remain = n;
    int res = 0;
    while (remain != 0) {
        res += remain % 2;
        remain /= 2;
    }
    return res;
}

int main() {
    auto f = [](int n, int expect) {
        int output = hammingWeight(n);
        leetcode_assert(output == expect, "hammingWeight n={} expect={} output={}", n, expect, output);
    };
    f(11, 3);
    f(128, 1);
    f(2147483645, 30);
}
