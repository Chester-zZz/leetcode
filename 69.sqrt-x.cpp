/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.67%)
 * Total Accepted:    333.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */
class Solution {
   public:
    int mySqrt(int x) {
        // 二分法
        // int i = 0, j = x / 2 + 1;
        // long long mid;
        // long long square;
        // while (i <= j) {
        //     mid = (i + j) / 2;
        //     square = mid * mid;
        //     if (square == x) {
        //         return mid;
        //     } else if (square > x) {
        //         j = mid - 1;
        //     } else {
        //         i = mid + 1;
        //     }
        // }
        // return j;

        // 牛顿法
        if (x == 0) {
            return 0;
        }
        double last = 0;
        double result = 1;
        while (last!=result) {
            // 直到两次结果足够相近
            last = result;
            result = (result + x / result) / 2;
        }
        return int(result);
    }
};
