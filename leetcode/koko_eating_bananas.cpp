//
// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int get_time(int K, vector<int> &piles) {
    int res = 0;
    for (int pile : piles) {
        int quotient = pile / K;
        int mod = pile % K;
        if (mod == 0) {
            res += quotient;
        } else {
            res += quotient + 1;
        }
    }
    return res;
}

int minEatingSpeed(vector<int> &piles, int h) {
    if (piles.empty()) {
        return 0;
    }
    if (h <= piles.size()) {
        return *max_element(piles.begin(), piles.end());
    }
    sort(piles.begin(), piles.end());
    int begin = 1, end = piles[piles.size() - 1];
    while (begin < end) {
        int mid = (begin + end) / 2;
        int time = get_time(mid, piles);
        if (time <= h) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return end;
}

int main() {
    auto f = [](vector<int> &&piles, int h, int expect) {
        auto output = minEatingSpeed(piles, h);
        leetcode_assert(output == expect, "koko_eating_bananas piles={} h={} expect={} output={}", piles, h, expect,
                        output);
    };
    f({3, 6, 7, 11}, 8, 4);
    f({30, 11, 23, 4, 20}, 5, 30);
    f({30, 11, 23, 4, 20}, 6, 23);
}
