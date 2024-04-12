//
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int maxLevelSum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    map<int, int, greater<>> mp;
    while (!q.empty()) {
        int size = q.size();
        int sum = 0;
        for (int i = 0; i < size; i++) {
            auto p = q.front();
            q.pop();
            sum += p->val;
            if (p->left) {
                q.push(p->left);
            }
            if (p->right) {
                q.push(p->right);
            }
        }
        auto it = mp.find(sum);
        if (it == mp.end()) {
            mp[sum] = level + 1;
        }
        level++;
    }
    return mp.begin()->second;
}

int main() {
    auto f = [](string &&tree_str, int expect) {
        auto output = maxLevelSum(buildTreeByStr(std::move(tree_str)));
        leetcode_assert(output == expect, "maximum_level_sum_of_a_binary_tree root={} expect={} output={}", tree_str, expect, output);
    };
    f("[1,7,0,7,-8,null,null]", 2);
    f("[989,null,10250,98693,-89388,null,null,null,-32127]", 2);
}
