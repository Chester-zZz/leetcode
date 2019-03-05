/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.51%)
 * Total Accepted:    260.2K
 * Total Submissions: 657.9K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 */
#include <iostream>
#include <string>
#include <vector>
class Solution {
   public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            // 递归得到上一个结果
            std::string last = countAndSay(n - 1);
            std::string result;
            char tmp_result;
            int index, count;
            char current_char;
            for (int i = 0; i < last.size();) {
                index = i;
                count = 0;
                current_char = last[index];
                while (current_char == last[index] && index != last.size()) {
                    // char相同的就累加
                    ++index;
                    ++count;
                }
                // 该char一共有这么多个
                tmp_result = count + '0';
                result += tmp_result;
                result += current_char;
                // 直接跳过已经检测过的部分
                i += count;
            }
            return result;
        }
    }
};
