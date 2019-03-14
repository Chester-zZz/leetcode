/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.26%)
 * Total Accepted:    148.6K
 * Total Submissions: 398.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Example 1:
 *
 *
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 *
 * Example 2:
 *
 *
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 */
class Solution {
   public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n) {
            result += n / 5;
            // 首先135/5 = 27，说明135以内有27个5的倍数；
            // 27/5=5，说明135以内有5个25的倍数；
            // 5/5=1，说明135以内有1个125的倍数
            n /= 5;
        }
        return result;
    }
};
