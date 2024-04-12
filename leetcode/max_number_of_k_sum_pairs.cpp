//
// https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int maxOperations(vector<int> &nums, int k) {
    int ans = 0;
    unordered_map<int, queue<int>> mp;
    vector<bool> used(nums.size(), false);
    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        auto it = mp.find(k - n);
        if (it == mp.end() || it->second.empty()) {
            mp[n].push(i);
            continue;
        }
        int index = it->second.front();
        used[index] = true;
        it->second.pop();
        ans++;
    }
    return ans;
}

// Better!
int maxOperationsV2(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int count = 0;
    while (i < j) {
        if (nums[i] + nums[j] == k) {
            count++;
            i++;
            j--;
        } else if (nums[i] + nums[j] > k) {
            j--;
        } else {
            i++;
        }
    }
    return count;
}

int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = maxOperationsV2(nums, k);
        leetcode_assert(output == expect, "max_number_of_k_sum_pairs nums={} k={} expect={} output={}", nums, k, expect,
                        output);
    };
    f({1, 2, 3, 4}, 5, 2);
    f({3, 1, 3, 4, 3}, 6, 1);
    f({2, 5, 4, 4, 1, 3, 4, 4, 1, 4, 4, 1, 2, 1, 2, 2, 3, 2, 4, 2}, 3, 4);
}
