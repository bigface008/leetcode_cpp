//
// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        getTreeHeight(root);
        dfs(root, -1, 0);
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(ansMap[q]);
        }
        return ans;
    }

private:
    unordered_map<int, int> subTreeHeightMap;
    unordered_map<int, int> ansMap;

    int getTreeHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = getTreeHeight(root->left);
        int right = getTreeHeight(root->right);
        int h = max(left, right) + 1;
        subTreeHeightMap[root->val] = h;
        return h;
    }

    void dfs(TreeNode *root, int depth, int restH) {
        if (!root) {
            return;
        }
        depth++;
        ansMap[root->val] = restH;
        int rightH = root->right ? subTreeHeightMap[root->right->val] : 0;
        int leftH = root->left ? subTreeHeightMap[root->left->val] : 0;
        dfs(root->left, depth, max(restH, depth + rightH));
        dfs(root->right, depth, max(restH, depth + leftH));
//        dfs(root->left, depth, max(restH, depth + subTreeHeightMap[root->right->val]));
//        dfs(root->right, depth, max(restH, depth + subTreeHeightMap[root->left->val]));
    }
};

class Solution2 {
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        getTreeHeight(root);
        bfs(root);
        fmt::println("subTreeHeightMap {}", subTreeHeightMap);
        fmt::println("levels {}", levels);
        fmt::println("heightMap {}", heightMap);
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(query(q));
        }
        return ans;
    }

private:
    unordered_map<int, int> subTreeHeightMap;
    unordered_map<int, int> ansMap;

    vector<vector<int>> levels;
    unordered_map<int, int> heightMap;
//    unordered_map<int, TreeNode *> nodeMap;

    int getTreeHeight(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = getTreeHeight(root->left);
        int right = getTreeHeight(root->right);
        int h = max(left, right) + 1;
        subTreeHeightMap[root->val] = h - 1;
        return h;
    }

    void bfs(TreeNode *root) {
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> levelVec;
            for (int i = 0; i < size; i++) {
                TreeNode *node = dq.front();
                dq.pop_front();
//                nodeMap[node->val] = node;
                heightMap[node->val] = levels.size();
                levelVec.push_back(node->val);
                if (node->left) {
                    dq.push_back(node->left);
                }
                if (node->right) {
                    dq.push_back(node->right);
                }
            }
            sort(levelVec.begin(), levelVec.end(), [&](int a, int b) {
                return subTreeHeightMap[a] < subTreeHeightMap[b];
            });
            levels.push_back(levelVec);
        }
    }

    int query(int q) {
        if (ansMap.contains(q)) {
            return ansMap[q];
        }
        int height = heightMap[q];
        vector<int> &level = levels[height];
        int ans = 0;
        if (level.size() == 1) {
            ans = height - 1;
        } else {
            if (level.back() == q) {
                ans = height + subTreeHeightMap[level[level.size() - 2]];
            } else {
                ans = levels.size() - 1;
            }
        }
        ansMap[q] = ans;
        return ans;
    }
};

class Solution3 {
private:
    vector<unordered_set<int>> levels;
    unordered_map<int, int> heightMap;
    unordered_map<int, TreeNode *> nodeMap;
    vector<int> ans;

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        levels.clear();
        heightMap.clear();
        nodeMap.clear();
        ans.clear();
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int size = dq.size();
            unordered_set<int> levelSet;
            for (int i = 0; i < size; i++) {
                TreeNode *node = dq.front();
                dq.pop_front();
                nodeMap[node->val] = node;
                heightMap[node->val] = levels.size();
                levelSet.insert(node->val);
                if (node->left) {
                    dq.push_back(node->left);
                }
                if (node->right) {
                    dq.push_back(node->right);
                }
            }
            levels.push_back(levelSet);
        }
//        fmt::println("levels {}", levels);
//        fmt::println("heightMap {}", heightMap);
//        fmt::println("nodeMap.size() {}", nodeMap.size());
//        fmt::println("nodeMap[1]->val {}", nodeMap[1]->val);
        unordered_map<int, int> ansMap;
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            if (ansMap.contains(q)) {
                ans.push_back(ansMap[q]);
            } else {
                ans.push_back(query(q));
            }
//            fmt::println("after i={} query={}", i, queries[i]);
//            fmt::println("  levels {}", levels);
//            fmt::println("  heightMap {}", heightMap);
//            fmt::println("  nodeMap.size() {}", nodeMap.size());
//            fmt::println("  nodeMap[1]->val {}", nodeMap[1]->val);
        }
        return ans;
    }

    int query(int q) {
        int height = heightMap[q];
        unordered_set<int> &level = levels[height];
        if (level.size() == 1) {
            return height - 1;
        }
        vector<unordered_set<int>> removedNodes;
        //        unordered_set<int> removedNodes;
        deque<int> dq;
        dq.push_back(q);
        int currHeight = height;
        while (!dq.empty()) {
            int size = dq.size();
            unordered_set<int> levelRemovedNodes;
            for (int i = 0; i < size; i++) {
                int idx = dq.front();
                dq.pop_front();
                levelRemovedNodes.insert(idx);
                levels[currHeight].erase(idx);
                TreeNode *node = nodeMap[idx];
                if (node->left) {
                    dq.push_back(node->left->val);
                }
                if (node->right) {
                    dq.push_back(node->right->val);
                }
            }
            removedNodes.push_back(levelRemovedNodes); // TODO: OPT?
            currHeight++;
        }
        // recover
        auto recover = [&]() {
//            fmt::println("q={} removedNodes={}", q, removedNodes);
            for (int h = 0; h < removedNodes.size(); h++) {
                unordered_set<int> &nodes = removedNodes[h];
                levels[h + height].insert(nodes.begin(), nodes.end());
            }
        };

        int ans = levels.size() - 1;
        if (currHeight < ans) {
            recover();
            return ans;
        }
        for (int h = height; h < levels.size(); h++) {
            if (levels[h].empty()) {
                ans = h - 1;
                break;
            }
        }
        recover();
        return ans;
    }
};

int main() {
    //    {
    //        TreeNode *root = new TreeNode(1);
    //        root->left = new TreeNode(3);
    //        root->left->left = new TreeNode(2);
    //        root->right = new TreeNode(4);
    //        root->right->left = new TreeNode(6);
    //        root->right->right = new TreeNode(5);
    //        root->right->right->right = new TreeNode(7);
    //        vector<int> queries{4};
    //        fmt::println("ans {}", Solution().treeQueries(root, queries));
    //    }
    //    {
    //        TreeNode *root = new TreeNode(5);
    //        root->left = new TreeNode(8);
    //        root->left->left = new TreeNode(2);
    //        root->left->left->left = new TreeNode(4);
    //        root->left->left->right = new TreeNode(6);
    //        root->left->right = new TreeNode(1);
    //        root->right = new TreeNode(9);
    //        root->right->left = new TreeNode(3);
    //        root->right->right = new TreeNode(7);
    //        vector<int> queries{3, 2, 4, 8};
    //        fmt::println("ans {}", Solution().treeQueries(root, queries));
    //    }
    {
        TreeNode *root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(5);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(6);
        root->right->left->right = new TreeNode(4);
        vector<int> queries{5, 5, 1, 6, 4, 5};
        fmt::println("ans {}", Solution().treeQueries(root, queries));
    }
    //    auto f = [](TreeNode* root, vector<int> &&queries, vector<int> &&expect) {
    //        auto output = Solution().treeQueries(root, queries);
    //        leetcode_assert(output == expect, "height_of_binary_tree_after_subtree_removal_queries root={} queries={}
    //        expect={} output={}", root, queries, expect, output);
    //    };
    //    f();
}
