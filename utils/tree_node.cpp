//
// Created by 汪喆昊 on 2024/1/3.
//

#include "tree_node.h"
#include <cmath>
#include <fmt/format.h>
#include <queue>
#include <vector>

using namespace std;

void preorderTraversal(TreeNode *n, vector<int> &vec) {
    if (!n) {
        vec.push_back(INT_MIN);
        return;
    }

    vec.push_back(n->val);
    preorderTraversal(n->left, vec);
    preorderTraversal(n->right, vec);
}

void breadthFirstSearch(TreeNode *root) {
    if (!root) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        auto *n = q.front();
        q.pop();
        fmt::print("{},", n->val);
        if (n->left) {
            q.push(n->left);
        }
        if (n->right) {
            q.push(n->right);
        }
    }
}

auto fmt::formatter<TreeNode>::format(TreeNode n, format_context& ctx) const -> decltype(ctx.out()) {
    vector<int> vec;
    vector<TreeNode *> nodes{&n};
    // BFS
    queue<TreeNode *> q;
    q.push(&n);
    while (!q.empty()) {
        auto *n = q.front();
        q.pop();
        if (!n) {
            vec.push_back(INT_MIN);
            continue;
        }
        vec.push_back(n->val);
        q.push(n->left);
        q.push(n->right);
    }
    string res = "[";
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == INT_MIN) {
            res.append("null");
        } else {
            res.append(to_string(vec[i]));
        }
        if (i != vec.size() - 1) {
            res.append(", ");
        } else {
            res.append("]");
        }
    }
    return formatter<string_view>::format(res, ctx);
}

void testFmtTree() {
    auto *t = new TreeNode(0);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);
//    t->left->left = new TreeNode(3);
    t->left->right = new TreeNode(4);
//    t->right->left = new TreeNode(5);
    t->right->right = new TreeNode(6);
    fmt::println("tree {}", *t);
//    breadthFirstSearch(t);
    freeTree(t);
}

TreeNode* buildTree(const std::vector<int>& nums, int index);

TreeNode *buildTreeByStr(const std::string &&treeStr) {
    vector<int> vec;
    int i = 0;
    while (i < treeStr.size()) {
        if (isdigit(treeStr[i])) {
            int num = treeStr[i] - '0';
            int j = i + 1;
            for (; j < treeStr.size(); ++j) {
                if (isdigit(treeStr[j])) {
                    num = num * 10 + treeStr[j] - '0';
                } else {
                    break;
                }
            }
            if (i != 0 && treeStr[i - 1] == '-') {
                num = -num;
            }
            i = j;
            vec.push_back(num);
        } else if (treeStr[i] == 'n') {
            vec.push_back(INT_MIN);
            i += 4;
        } else {
            ++i;
        }
    }
    return buildTree(std::move(vec), 0);
}

int TreeNode::depth() const {
    int leftDepth = 0, rightDepth = 0;
    if (left) {
        leftDepth = left->depth();
    }
    if (right) {
        rightDepth = right->depth();
    }
    return 1 + max(leftDepth, rightDepth);
}

int TreeNode::childCount() const {
    int cnt = 0;
    if (left) {
        ++cnt;
    }
    if (right) {
        ++cnt;
    }
    return cnt;
}

TreeNode* buildTree(const std::vector<int>& nums) {
    return buildTree(std::move(nums), 0);
}

// 你得传一个每层都满的 tree 进来才能正常解析，比如有的层已经空了一部分节点，你仍然需要填充对应的 null ，这里用 INT_MIN 来代替。
TreeNode* buildTree(const std::vector<int>& nums, int index) {
    if (index >= nums.size() || nums[index] == INT_MIN) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(nums[index]);
    node->left = buildTree(nums, 2 * index + 1);
    node->right = buildTree(nums, 2 * index + 2);
    return node;
}

void freeTree(TreeNode *node) {
    if (!node) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p) {
        if (!q) {
            return true;
        } else {
            return false;
        }
    } else {
        if (!q) {
            return false;
        } else {
            if (p->val != q->val) {
                return false;
            }
            if (!isSameTree(p->right, q->right)) {
                return false;
            }
            if (!isSameTree(p->left, q->left)) {
                return false;
            }
            return true;
        }
    }
}

bool isSameTree(TreeNode *tree1, const std::string &&treeStr) {
    auto *tree0 = buildTreeByStr(std::move(treeStr));
    bool isSame = isSameTree(tree0, tree1);
    freeTree(tree0);
    return isSame;
}

/*
 * 0
 * 1 2
 * 3 4 5 6
 */
void printTree(TreeNode *tree) {
//    int i = 0;
//    while ()
//    int levels = tree->depth();
//    for (int i = 0; i < levels; ++i) {
//        int levelCnt = pow(2, i);
//        for (int j = 0; j < )
//    }
}