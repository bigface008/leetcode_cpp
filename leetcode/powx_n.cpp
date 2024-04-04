//
// Created by 汪喆昊 on 2024/4/3.
// https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

double myPow(double x, int n) {
    if (x == 1 || n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    bool reverse = n < 0;
    int half = n / 2;
    int half_abs = abs(half);
    int rest = n - half;
    double half_pow = myPow(x, half_abs);

    double pow_temp = half_pow * half_pow;
    if (rest != half) {
        pow_temp *= x;
    }
    if (n < 0) {
        return 1.0 / pow_temp;
    } else {
        return pow_temp;
    }
}

int main() {
    auto f = [](double x, int n, double expect) {
        double output = myPow(x, n);
        leetcode_assert(output == expect, "pow x={} n={} expect={} output={}", x, n, expect, output);
    };
    f(2.0, 10, 1024.0);
    f(2.1, 3, 9.261);
    f(2.0, -2, 0.25);
}
