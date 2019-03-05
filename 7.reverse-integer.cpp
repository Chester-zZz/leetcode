/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.12%)
 * Total Accepted:    613.4K
 * Total Submissions: 2.4M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 *
 */
#include <limits.h>
class Solution {
   public:
    int reverse(int x) {
        int a = 0;
        int result = 0;
        while (x) {
            a = x % 10;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && a < -8)) {
                return 0;
            }
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && a > 7)){
                return 0;
            }
            result = result * 10 + a;
            x /= 10;
        }
        return result;
    }
};
