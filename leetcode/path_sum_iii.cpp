//
// https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

void dfs(TreeNode *node, map<long, set<TreeNode *>> &sum_map, const int target, int &count) {
    if (!node) {
        return;
    }
    int remain = target - node->val;
    auto it = sum_map.find(remain);
    if (it != sum_map.end() && !it->second.empty()) {
        count += it->second.size();
    }
    if (remain == 0) {
        count++;
    }
    map<long, set<TreeNode *>> new_mp;
    for (auto &p : sum_map) {
        new_mp[p.first + node->val] = p.second;
    }
    new_mp[node->val].insert(node);
    dfs(node->left, new_mp, target, count);
    dfs(node->right, new_mp, target, count);
    new_mp[node->val].erase(node);
}

int pathSum(TreeNode *root, int targetSum) {
    int count = 0;
    map<long, set<TreeNode *>> sum_map;
    dfs(root, sum_map, targetSum, count);
    return count;
}

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode *root, long long targetSum) {
        if (!root) {
            return;
        }
        if (root->val == targetSum) {
            ans++;
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode *root, int targetSum) {
        if (root) {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};

int main() {
    auto f = [](string &&treeStr, int targetSum, int expect) {
        auto sol = Solution();
        auto output = sol.pathSum(buildTreeByStr(std::move(treeStr)), targetSum);
        leetcode_assert(output == expect, "path_sum_iii root={} targetSum={} expect={} output={}", treeStr, targetSum,
                        expect, output);
    };
    f("[10,5,-3,3,2,null,11,3,-2,null,1]", 8, 3);
    f("[5,4,8,11,null,13,4,7,2,null,null,5,1]", 22, 3);
    f("[1]", 1, 1);
    f("[0,1,1]", 1, 4);
}
