/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.68%)
 * Total Accepted:    356.8K
 * Total Submissions: 876.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 *
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 *
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *
 *
 * Example 2:
 *
 *
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 *
 */
#include <vector>
class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int k = digits.size();
        while (k > 0) {
            --k;
            if ((digits[k] + 1) % 10 != 0) {
                digits[k] += 1;
                break;
            } else {
                digits[k] = 0;
            }
        }
        if (k == 0 && digits[k]==0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
