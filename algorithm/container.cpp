//
// Created by 汪喆昊 on 2024/4/13.
//

#include "leetcode_utils.hpp"

using namespace std;

class PriorityQueue {
    friend auto format_as(PriorityQueue const& q) {
        return fmt::format("priority queue: [{}]", q.buff);
    }

public:
    PriorityQueue() = default;

    void push(pair<int, int> p) {
        buff.push_back(p);
        move_up(buff.size() - 1);
    }

    void pop() {
        if (buff.empty()) {
            return;
        }
        swap(buff[0], buff[buff.size() - 1]);
        buff.pop_back();
        move_down(buff.size(), 0);
    }

    pair<int, int> top() {
        if (buff.empty()) {
            return {0, 0};
        }
        return buff[0];
    }

    int size() const {
        return buff.size();
    }


private:
    vector<pair<int, int>> buff;

    void move_up(int child) {
        int parent = (child - 1) / 2;
        while (child > 0) {
            if (buff[parent].first < buff[child].first) {
                swap(buff[parent], buff[child]);
                child = parent;
                parent = (child - 1) / 2;
            } else {
                break;
            }
        }
    }

    void move_down(int n, int parent) {
        int child = 2 * parent + 1;
        while (child < n) {
            if (child + 1 < n && buff[child].first < buff[child + 1].first) {
                child++; // If right child node is bigger, chose the right one.
            }
            if (buff[parent].first < buff[child].first) {
                swap(buff[parent], buff[child]);
//                swap(buff[parent].first, buff[child].first);
//                swap(buff[parent].second, buff[child].second);
                parent = child;
                child = 2 * parent + 1;
            } else {
                break;
            }
        }
    }
};

class BinarySearchTree {
public:
    BinarySearchTree(): root(nullptr) {}

    bool search(int val) const {
        return search(root, val);
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool remove(int val) {
        return remove(root, val);
    }

private:
    TreeNode *root;

    TreeNode *insert(TreeNode *node, int val) {
        if (!node) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    bool search(TreeNode *node, int val) const {
        if (!node) {
            return false;
        }
        if (val < node->val) {
            return search(node->left, val);
        } else if (val > node->val) {
            return search(node->right, val);
        } else {
            return true;
        }
    }

    bool remove(TreeNode *&node, int val) {
        if (!node) {
            return false;
        }

        if (val < node->val) {
            return remove(node->left, val);
        } else if (val > node->val) {
            return remove(node->right, val);
        } else {
            // 找到了要删除的节点
            if (node->left && node->right) {
                // 如果要删除的节点的左右子树都存在
                // 在右子树中查找最左边的叶子节点
                TreeNode *temp = node->right;
                while (temp->left) {
                    temp = temp->left;
                }
                // 用右子树中最左叶子节点的值，填充即将删除的节点的值
                node->val = temp->val;
                // 接着递归删除右子树中这个最左叶子节点的值
                return remove(node->right, node->val);
            } else {
                TreeNode *temp = node;
                if (!node->left) {
                    node = node->right;
                } else {
                    node = node->left;
                }
                delete temp;
                return true;
            }
        }
    }
};

int main() {
//    auto q = PriorityQueue();
//    q.push({-5, 23});
//    q.push({12, 12});
//    q.push({1, 2});
//    fmt::println("{}", q);
    auto tr = BinarySearchTree();
    tr.insert(8);
    tr.insert(6);
    tr.insert(7);
    tr.search(7);
    tr.remove(6);
    fmt::println("search 7 {}", tr.search(7));
//    tr.insert(12);
//    tr.insert(15);
//    tr.insert(13);
//    tr.insert(14);
//    tr.insert(1);
//    tr.insert(2);
//    tr.insert(-3);
//    tr.insert(22);
//    tr.insert(17);
//    tr.insert(18);
//    tr.insert(25);
//    tr.insert(23);
//    tr.remove(22);
//    fmt::println("tr.search(22) {}", tr.search(22));
//    tr.remove(24);
//    fmt::println("tr.search(24) {}", tr.search(24));
//    tr.remove(1);
//    fmt::println("tr.search(1) {}", tr.search(1));
}