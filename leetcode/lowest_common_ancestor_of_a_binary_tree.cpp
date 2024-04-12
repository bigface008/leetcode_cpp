//
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

// 这个函数本质上是检查p和q是不是root的子节点。如果是root的子节点，就返回root。如果是left的子节点，返回left。如果是right的子节点，就返回right。
TreeNode *findNode(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || p == root || q == root) {
        return root;
    }
    auto *left = findNode(root->left, p, q);
    auto *right = findNode(root->right, p, q);
    if (!left) {
        if (!right) {
            return nullptr;
        } else {
            return right;
        }
    } else {
        if (!right) {
            return left;
        } else {
            return root;
        }
    }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) { return findNode(root, p, q); }

int main() {
    auto *root = buildTreeByStr("[3,5,1,6,2,0,8,null,null,7,4]");
    auto *node_5 = root->left;
    auto *node_4 = root->left->right->right;
    auto *node_1 = root->right;
    fmt::println("5 1: {}", lowestCommonAncestor(root, node_5, node_1)->val);
    fmt::println("5 4: {}", lowestCommonAncestor(root, node_5, node_4)->val);
}
