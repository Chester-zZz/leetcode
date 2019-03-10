/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (42.70%)
 * Total Accepted:    363K
 * Total Submissions: 848.8K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 * But the following [1,2,2,null,3,null,3]  is not:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
#include <queue>
class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        // 递归
        // return isSymmetric(root->left, root->right);

        // 迭代
        std::queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        TreeNode* tmp_node_1;
        TreeNode* tmp_node_2;

        while (!q1.empty() && !q2.empty()) {
            tmp_node_1 = q1.front();
            q1.pop();
            tmp_node_2 = q2.front();
            q2.pop();
            if(!tmp_node_1 && !tmp_node_2){
                continue;
            }
            if(!tmp_node_1 || !tmp_node_2){
                return false;
            }
            if(tmp_node_1->val!=tmp_node_2->val){
                return false;
            }
            q1.push(tmp_node_1->left);
            q1.push(tmp_node_1->right);

            q2.push(tmp_node_2->right);
            q2.push(tmp_node_2->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        if (!t1 || !t2) {
            return false;
        }
        return t1->val == t2->val && isSymmetric(t1->left, t2->right) &&
               isSymmetric(t1->right, t2->left);
    }
};
