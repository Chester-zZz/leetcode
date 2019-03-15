/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.34%)
 * Total Accepted:    327K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
#include <cctype>
#include <string>
class Solution {
   public:
    bool isPalindrome(std::string s) {
        int right = s.size();
        if (right == 0) {
            return true;
        }
        int left = 0;
        --right;
        while(left <= right) {
            if (!isalnum(s[left])) {
                ++left;
            } else if (!isalnum(s[right])) {
                --right;
            } else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
