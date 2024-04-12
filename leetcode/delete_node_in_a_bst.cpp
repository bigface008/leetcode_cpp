//
// https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

pair<TreeNode *, TreeNode *> helper(TreeNode *node, TreeNode *parent, int key) {
    if (!node) {
        return {nullptr, parent};
    }
    if (node->val == key) {
        return {node, parent};
    } else if (node->val > key) {
        return helper(node->left, node, key);
    } else {
        return helper(node->right, node, key);
    }
}

TreeNode *deleteNode(TreeNode *root, int key) {
    auto [node, parent] = helper(root, nullptr, key);
    if (!node) {
        return nullptr;
    }
    TreeNode **parent_ptr = nullptr;
    if (parent) {
        if (parent->left == node) {
            parent_ptr = &parent->left;
        } else {
            parent_ptr = &parent->right;
        }
    }
    TreeNode *new_node = nullptr;
    if (node->right) {
        if (node->left) {
            new_node = node->right;
            new_node->left
        } else {
            new_node = node->right;
        }
    } else {
        if (node->left) {
            new_node = node->left;
        }
    }
    if (parent_ptr) {
        *parent_ptr = new_node;
    }
    return new_node;
}

int findMax(TreeNode *root) {
    auto *n = root;
    while (n->right) {
        n = n->right;
    }
    return n->val;
}

TreeNode *deleteNodeV2(TreeNode *root, int key) {
    if (!root) {
        return nullptr;
    }
    if (root->val > key) {
        root->left = deleteNodeV2(root->left, key);
        return root;
    } else if (root->val < key) {
        root->right = deleteNodeV2(root->right, key);
        return root;
    } else {
        if (!root->left) {
            if (!root->right) {
                return nullptr;
            } else {
                return root->right;
            }
        } else {
            if (!root->right) {
                return root->left;
            } else {
                int max_val = findMax(root->left);
                root->val = max_val;
                root->left = deleteNodeV2(root->left, max_val);
                return root;
            }
        }
    }
}

int main() {
    {
        auto *root = buildTreeByStr("[5,3,6,2,4,null,7]");
        auto *res = deleteNode(root, 3);
        fmt::println("{}", root->val);
    }
}
