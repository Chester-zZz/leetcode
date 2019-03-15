/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (29.10%)
 * Total Accepted:    272K
 * Total Submissions: 933.8K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 *
 *
 * Note:
 *
 *
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 *
 */
#include <vector>
class Solution {
   public:
    void rotate(std::vector<int>& nums, int k) {
        if (k == 0 || nums.empty() || k % nums.size() == 0) {
            return;
        }
        int start = 0, previous = 0, current = nums[0], dynamic_pos = 0, size = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            previous = current;
            dynamic_pos = (dynamic_pos + k) % size;
            current = nums[dynamic_pos];
            nums[dynamic_pos] = previous;
            if (dynamic_pos == start) {
                dynamic_pos = ++start;
                current = nums[dynamic_pos];
            }
        }
        return;
    }
};
