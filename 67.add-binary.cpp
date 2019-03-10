/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (37.94%)
 * Total Accepted:    278.4K
 * Total Submissions: 732.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 *
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Example 1:
 *
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 *
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 */
#include <string>
#include <algorithm>
class Solution {
   public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int sum = 0;
        int la = a.size();
        int lb = b.size();
        while (la > 0 || lb > 0 || sum == 1) {
            --la;
            --lb;
            if (la >= 0) {
                sum += a[la] - '0';
            }
            if (lb >= 0) {
                sum += b[lb] - '0';
            }
            result.push_back(sum % 2 + '0');
            sum /= 2;
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};
