/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.25%)
 * Total Accepted:    240.5K
 * Total Submissions: 487.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
#include <vector>
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Solution {
   public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        int size = nums.size();
        return get_tree(nums, 0, size - 1);
    }
    TreeNode* get_tree(std::vector<int>& nums, int left, int right) {
        // if(left==right){
        //     return new TreeNode(nums[left]);
        // }
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* new_tree = new TreeNode(nums[mid]);
        new_tree->left = get_tree(nums, left, mid - 1);
        new_tree->right = get_tree(nums, mid + 1, right);
        return new_tree;
    }
};
