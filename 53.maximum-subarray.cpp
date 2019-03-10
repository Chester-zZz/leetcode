/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.79%)
 * Total Accepted:    470.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
#include <limits.h>
#include <vector>
class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        // O(n)
        int result = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 前面的和是负数，不要
            sum = sum + nums[i] > nums[i] ? sum + nums[i] : nums[i];
            // 如果后面一个数是负数，则保持现阶段结果不变
            result = result > sum ? result : sum;
        }
        return result;

        // O(nlogn)
        // return sub_sum(nums, 0, nums.size() - 1);
    };
    int sub_sum(std::vector<int>& nums, int left, int right) {
        if (left >= right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int left_max = sub_sum(nums, left, mid - 1);
        int right_max = sub_sum(nums, mid + 1, right);
        int mid_max = nums[mid];
        int t = mid_max;
        for (int i = mid - 1; i >= left; --i) {
            t += nums[i];
            mid_max = mid_max > t ? mid_max : t;
        }
        t = mid_max;
        for (int i = mid + 1; i <= right; ++i) {
            t += nums[i];
            mid_max = mid_max > t ? mid_max : t;
        }
        return std::max(left_max, std::max(mid_max, right_max));
    }
};
