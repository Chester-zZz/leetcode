/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.15%)
 * Total Accepted:    247.8K
 * Total Submissions: 770.9K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 *
 * Example:
 *
 * Input: "Hello World"
 * Output: 5
 *
 *
 */
#include <string>
class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        if (s.empty()) {
            return 0;
        }
        int result = 0;
        int last_char = s.size() - 1;
        while (last_char >= 0 && s[last_char] == ' ') {
            --last_char;
        }
        while (last_char >= 0 && s[last_char] != ' ') {
            ++result;
            --last_char;
        }
        return result;
    }
};
