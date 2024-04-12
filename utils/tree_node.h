//
// Created by 汪喆昊 on 2024/1/3.
//

#include <string>
#include <vector>
#include "fmt/format.h"

#ifndef TREENODE_H
#define TREENODE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int depth() const;

    int childCount() const;
};

template <>
struct fmt::formatter<TreeNode> : formatter<string_view> {
    auto format(TreeNode n, format_context &ctx) const -> decltype(ctx.out());
};

void breadthFirstSearch(TreeNode *node);

void testFmtTree();

TreeNode *buildTreeByStr(const std::string &&treeStr);

TreeNode *buildTree(const std::vector<int> &nums);

void freeTree(TreeNode *node);

bool isSameTree(TreeNode *p, TreeNode *q);

bool isSameTree(TreeNode *res, const std::string &&treeStr);

void printTree(TreeNode *tree);

class TreeNodeWithNext {
public:
    int val;
    TreeNodeWithNext *left;
    TreeNodeWithNext *right;
    TreeNodeWithNext *next;

    TreeNodeWithNext() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNodeWithNext(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNodeWithNext(int _val, TreeNodeWithNext *_left, TreeNodeWithNext *_right, TreeNodeWithNext *_next) :
        val(_val), left(_left), right(_right), next(_next) {}
};

class NodeWithNeighbors {
public:
    int val;
    std::vector<NodeWithNeighbors *> neighbors;

    NodeWithNeighbors() {
        val = 0;
        neighbors = std::vector<NodeWithNeighbors *>();
    }

    NodeWithNeighbors(int _val) {
        val = _val;
        neighbors = std::vector<NodeWithNeighbors *>();
    }

    NodeWithNeighbors(int _val, std::vector<NodeWithNeighbors *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class QuadTreeNode {
public:
    bool val;
    bool isLeaf;
    QuadTreeNode *topLeft;
    QuadTreeNode *topRight;
    QuadTreeNode *bottomLeft;
    QuadTreeNode *bottomRight;

    QuadTreeNode() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadTreeNode(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadTreeNode(bool _val, bool _isLeaf, QuadTreeNode *_topLeft, QuadTreeNode *_topRight, QuadTreeNode *_bottomLeft,
                 QuadTreeNode *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

#endif // TREENODE_H
