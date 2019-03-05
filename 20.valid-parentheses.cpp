/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.88%)
 * Total Accepted:    519.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
#include <map>
#include <stack>
#include <string>

class Solution {
   public:
    bool isValid(std::string s) {
        char tmp_char = s[0];
        if (tmp_char == ')' || tmp_char == ']' || tmp_char == '}') {
            return false;
        }
        std::stack<char> tmp_stack;
        for (int i = 0; i < s.size(); ++i) {
            tmp_char = s[i];
            if (tmp_char == '(' || tmp_char == '[' || tmp_char == '{') {
                tmp_stack.push(tmp_char);
            }
            if(tmp_stack.empty()){
                return false;
            }
            switch (tmp_char) {
                case ')':
                    if (tmp_stack.top() == '(') {
                        tmp_stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (tmp_stack.top() == '[') {
                        tmp_stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (tmp_stack.top() == '{') {
                        tmp_stack.pop();
                    } else {
                        return false;
                    }
                    break;

                default:
                    break;
            }
        }
        if(tmp_stack.empty()){
            return true;
        }else{
            return false;
        }
    }
};
