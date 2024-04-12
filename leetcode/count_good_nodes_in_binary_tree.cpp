//
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

void dfs(TreeNode *node, int &count, int curr_max) {
    if (!node) {
        return;
    }
    if (node->val >= curr_max) {
        curr_max = node->val;
        count++;
    }
    dfs(node->right, count, curr_max);
    dfs(node->left, count, curr_max);
}

int goodNodes(TreeNode* root) {
    int count = 0;
    dfs(root, count, INT_MIN);
    return count;
}

int main() {
    auto f = [](string &&treeStr, int expect) {
        auto output = goodNodes(buildTreeByStr(std::move(treeStr)));
        leetcode_assert(output == expect, "count_good_nodes_in_binary_tree root={} expect={} output={}", treeStr, expect, output);
    };
    f("[3,1,4,3,null,1,5]", 4);
    f("[3,3,null,4,2]", 3);
    f("[1]", 1);
}
