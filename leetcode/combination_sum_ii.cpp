//
// https://leetcode.com/problems/combination-sum-ii/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected;
        dfs(target, selected, candidates);
        return ans;
    }

private:
    vector<vector<int>> ans;

    void dfs(int target, vector<int>& selected, vector<int>& candidates) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            vector<int> temp;
            for (int i : selected) {
                temp.push_back(candidates[i]);
            }
            ans.push_back(temp);
            return;
        }
        int start = selected.empty() ? 0 : selected.back() + 1;
        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            int x = candidates[i];
            if (target >= x) {
                selected.push_back(i);
                dfs(target - x, selected, candidates);
                selected.pop_back();
            }
        }
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> selected;
        unordered_set<int> cand(candidates.begin(), candidates.end());
        dfs(target, selected, cand);
        return ans;
    }

private:
    vector<vector<int>> ans;

    void dfs(int target, vector<int>& selected, unordered_set<int>& candidates) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(selected);
            return;
        }
        for (int x : candidates) {
            unordered_set<int> cand(candidates);
            cand.erase(x);
            selected.push_back(x);
            dfs(target - x, selected, cand);
            selected.pop_back();
        }
    }
};


int main() {
    auto f = [](vector<int>&& candidates, int target, vector<vector<int>> expect) {
        auto output = Solution().combinationSum2(candidates, target);
        leetcode_assert(output == expect, "combination_sum_ii candidates={} target={} expect={} output={}", candidates, target, expect, output);
    };
    f();
}
