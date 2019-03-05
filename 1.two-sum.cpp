/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (41.93%)
 * Total Accepted:    1.5M
 * Total Submissions: 3.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */
#include <map>
#include <vector>
class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> tmp_map;
        std::map<int,int>::iterator iter;
        for (int i = 0; i < nums.size(); ++i) {
            iter = tmp_map.find(nums[i]);
            if (iter == tmp_map.end()) {
                tmp_map[target-nums[i]] = i;
                continue;
            } else {
                return std::vector<int>{tmp_map[nums[i]], i};
            }
        }
        return std::vector<int>{-1,-1};
    }
};
