/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.64%)
 * Total Accepted:    210.9K
 * Total Submissions: 461.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its bottom-up level order traversal as:
 *
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 *
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
#include <vector>
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Solution {
   public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }
        fill_next_level(result, root, 1);
        std::reverse(result.begin(), result.end());
        return result;
    }
    void fill_next_level(std::vector<std::vector<int>>& result, TreeNode* node, int level) {
        if (!node) {
            return;
        }
        if (level > result.size()) {
            // 如果发现还没有这一层的容器，则新增
            result.emplace_back(std::vector<int>());
        }
        // 把本node添加进来
        result[level - 1].emplace_back(node->val);

        // 下一层
        if (node->left) {
            fill_next_level(result, node->left, level + 1);
        }
        if (node->right) {
            fill_next_level(result, node->right, level + 1);
        }
    }
};
