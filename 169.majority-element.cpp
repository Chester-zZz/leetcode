/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (51.64%)
 * Total Accepted:    354K
 * Total Submissions: 685.2K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */
#include <vector>
class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        // 用map很简单，不写了
        // 这是一种投票法
        int result;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                result = num;
                ++count;
            } else {
                result == num ? ++count : --count;
            }
        }
        return result;
    }
};
