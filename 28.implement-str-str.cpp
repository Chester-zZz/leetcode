/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.24%)
 * Total Accepted:    384.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 *
 * Example 1:
 *
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 *
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 *
 */
#include <string>
class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) {
            return 0;
        }
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        if (haystack_size < needle_size) {
            return -1;
        }

        // 暴力
        // int i = 0, j = 0;
        // while (i < haystack_size && j < needle_size) {
        //     if (haystack[i] == needle[j]) {
        //         ++i;
        //         ++j;
        //     } else {
        //         i = i - j + 1;
        //         j = 0;
        //     }
        // }
        // if(j==needle_size){
        //     return i-j;
        // }
        // return -1;

        // KMP
        int next[needle_size];
        get_next(needle, next);
        int i = 0, j = 0;
        while ((j < needle_size) && (i < haystack_size)) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++j;
                ++i;
            } else {
                j = next[j];
            }
        }
        return j == needle_size ? i - j : -1;
    }

   private:
    void get_next(const std::string& needle, int* next) {
        int j = -1, i = 0;
        next[0]=-1;
        while (i < needle.size() - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};
