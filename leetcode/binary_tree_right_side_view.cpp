//
// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<int> res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            auto *node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            if (i == level_size - 1) {
                res.push_back(node->val);
            }
        }
    }
    return res;
}

int main() {
    auto f = [](string &&tree_str, vector<int> &&expect) {
        auto output = rightSideView(buildTreeByStr(std::move(tree_str)));
        leetcode_assert(output == expect, "binary_tree_right_side_view root={} expect={} output={}", tree_str, expect, output);
    };
    f("[1,2,3,null,5,null,4]", {1, 3, 4});
    f("[1,null,3]", {1, 3});
    f("[]", {});
}
