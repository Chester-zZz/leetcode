/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (44.70%)
 * Total Accepted:    231K
 * Total Submissions: 516.8K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
#include <vector>
class Solution {
   public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return std::vector<std::vector<int>>();
        }
        std::vector<std::vector<int>> result;
        result.emplace_back(std::vector<int>{1});
        for (int row = 1; row < numRows; ++row) {
            result.emplace_back(std::vector<int>(row + 1, 1));
            for (int col = 1; col < row; ++col) {
                result[row][col] = result[row - 1][col - 1] + result[row - 1][col];
            }
        }
        return result;
    }
};
