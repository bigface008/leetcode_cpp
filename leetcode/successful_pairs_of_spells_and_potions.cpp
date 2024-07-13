//
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    vector<int> res;
    sort(potions.begin(), potions.end());
    for (int spell : spells) {
        vector<long long> temp(potions.size(), 0);
        int threshold = success / spell;
        int mod = success % spell;
        int cnt = 0;
        //        if (mod == 0) {
        //            cnt = potions.end() - lower_bound(potions.begin(), potions.end(), threshold);
        //        } else {
        //            cnt = potions.end() - upper_bound(potions.begin(), potions.end(), threshold);
        //        }
        int begin = 0, end = potions.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (spell * (long long)potions[mid] >= success) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        res.push_back(potions.size() - begin);
    }
    return res;
}


int main() {
    auto f = [](vector<int> &&spells, vector<int> &&potions, long long success, vector<int> &&expect) {
        auto output = successfulPairs(spells, potions, success);
        leetcode_assert(output == expect,
                        "successful_pairs_of_spells_and_potions spells={} potions={} success={} expect={} output={}",
                        spells, potions, success, expect, output);
    };
    f({5, 1, 3}, {1, 2, 3, 4, 5}, 7, {4, 0, 3});
    f({3, 1, 2}, {8, 5, 8}, 16, {2, 0, 2});
}
