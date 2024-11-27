//
// https://leetcode.com/problems/unique-number-of-occurrences/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counter;
        for (int x : arr) {
            counter[x]++;
        }
        unordered_set<int> freq;
        for (auto [k, v] : counter) {
            if (freq.contains(v)) {
                return false;
            }
            freq.insert(v);
        }
        return true;
    }
};


int main() {
    auto f = [](vector<int>&& arr, bool expect) {
        auto output = Solution().uniqueOccurrences(arr);
        leetcode_assert(output == expect, "unique_number_of_occurrences arr={} expect={} output={}", arr, expect, output);
    };
    f();
}
