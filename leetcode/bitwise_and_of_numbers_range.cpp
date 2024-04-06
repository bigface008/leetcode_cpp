//
// https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int m = left, n = right;
    int shift = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        shift++;
    }
    return (m << shift);
}


int main() {
    auto f = [](int left, int right, int expect) {
        auto output = rangeBitwiseAnd(left, right);
        leetcode_assert(output == expect, "bitwise_and_of_numbers_range left={} right={} expect={} output={}", left, right, expect, output);
    };
    f(5, 7, 4);
    f(0, 0, 0);
    f(1, 2147483647, 0);
}
