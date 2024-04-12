//
// https://leetcode.com/problems/path-sum-ii/
//

#include "leetcode_utils.hpp"

using namespace std;

void dfs(TreeNode *node, vector<int> &path, int sum, const int targetSum, vector<vector<int>> &res) {
    if (!node) {
        //        if (sum == targetSum) {
        //            res.push_back(path);
        //        }
        return;
    }
    int after = sum + node->val;
    if (after == targetSum) {
        if (!node->left && !node->right) {
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
    } else if (after > targetSum) {
        return;
    }
    path.push_back(node->val);
    dfs(node->left, path, after, targetSum, res);
    dfs(node->right, path, after, targetSum, res);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(root, path, 0, targetSum, res);
    return res;
}

int main() {
    auto f = [](string &&tree_str, int targetSum, vector<vector<int>> &&expect) {
//        auto *root = buildTreeByStr(std::move(tree_str));
        auto output = pathSum(buildTreeByStr(std::move(tree_str)), targetSum);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "path_sum_ii root={} targetSum={} expect={} output={}", tree_str, targetSum, expect,
                        output);
    };
    //    f("[5,4,8,11,null,13,4,7,2,null,null,null,null,5,1]", 22, {{5, 4, 11, 2}, {5, 8, 4, 5}});
    //    f("[1,2,3]", 5, {});
    //    f("[1,2]", 0, {});
    f("[2,null,3]", 5, {{2, 3}});
}
