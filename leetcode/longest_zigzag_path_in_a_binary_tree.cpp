//
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int max_cnt;

    void dfs(TreeNode *node, int left, int right) {
        if (!node) {
            return;
        }
        max_cnt = max({max_cnt, left, right});
        dfs(node->left, right + 1, 0);
        dfs(node->right, 0, left + 1);
    }

    int longestZigZag(TreeNode *root) {
        dfs(root, 0, 0);
        return max_cnt;
    }
};

class SolutionV3 {
public:
    enum Direction { Unknown = -1, Left = 0, Right = 1 };

    int maxLength;

    // dfs返回值是void，我们通过引用传递maxLength来更新最长路径长度
    // direction: -1 = root, 0 = left, 1 = right
    void dfs(TreeNode *node, Direction direction, int length) {
        if (!node)
            return;
        maxLength = max(maxLength, length);
        // 向左走
        if (direction != Left)
            dfs(node->left, Left, length + 1); // 上一步向右，这步向左
        else
            dfs(node->left, Left, 1); // 重置长度
        // 向右走
        if (direction != Right)
            dfs(node->right, Right, length + 1); // 上一步向左，这步向右
        else
            dfs(node->right, Right, 1); // 重置长度
    }

    int longestZigZag(TreeNode *root) {
        dfs(root, Unknown, 0); // -1 表示方向未定，0 表示当前长度为0
        return maxLength;
    }
};

class SolutionV2 {
public:
    enum Direction { Unknown = -1, Left = 0, Right = 1 };

    int max_cnt;

    void dfs(TreeNode *node, int curr_cnt, Direction direction) {
        if (!node) {
            return;
        }
        max_cnt = max(max_cnt, curr_cnt);
        switch (direction) {
        case Unknown:
            {
                dfs(node->left, curr_cnt + 1, Left);
                dfs(node->right, curr_cnt + 1, Left);
                break;
            }
        case Left:
            {

                break;
            }
        case Right:
            break;
        }
    }

    int longestZigZag(TreeNode *root) {
        if (!root) {
            return 0;
        }
        dfs(root, 0, Direction::Unknown);
        return max_cnt;
    }
};


int main() {
    auto f = [](string &&tree_str, int expect) {
        auto sol = SolutionV3();
        auto output = sol.longestZigZag(buildTreeByStr(std::move(tree_str)));
        leetcode_assert(output == expect, "longest_zigzag_path_in_a_binary_tree root={} expect={} output={}", tree_str,
                        expect, output);
    };
    //    f("[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]", 3);
    f("[1,1,1,null,1,null,null,null,null,1,1,null,null,null,null,null,null,null,null,null,1]", 4);
    //    f("[1]", 0);
}
