/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (40.46%)
 * Total Accepted:    363.7K
 * Total Submissions: 898.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */
#include <vector>
class Solution {
   public:
    int searchInsert(std::vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0 || target <= nums[0]) {
            return 0;
        }
        if (target > nums[size - 1]) {
            return size;
        }
        // int i=0;
        // while(i!=size-1){
        //     if(nums[i]<target && target<=nums[i+1]){
        //         break;
        //     }
        //     ++i;
        // }
        // return i+1;
        for (int i = 0; i != size - 1; ++i) {
            if (nums[i] < target && target <= nums[i + 1]) {
                return i + 1;
            }
        }
        return -1;
    }
};
