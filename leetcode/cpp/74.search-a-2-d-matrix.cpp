/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int start = 0, end = matrix.size() - 1;
    int mid = (start + end) / 2;
    while (start < mid) {
      if (matrix[mid][0] > target) {
        end = mid;
      } else if (matrix[mid][0] < target) {
        start = mid;
      } else {
        return true;
      }
      mid = (start + end) / 2;
    }
    int row;
    if (start + 1 < matrix.size() && matrix[start + 1][0] <= target) {
      row = start + 1;
    } else
      row = start;
    start = 0;
    end = matrix[0].size() - 1;
    mid = (start + end) / 2;
    while (start < mid) {
      if (matrix[row][mid] > target) {
        end = mid;
      } else if (matrix[row][mid] < target) {
        start = mid;
      } else {
        return true;
      }
      mid = (start + end) / 2;
    }
    return (matrix[row][start] == target) || (matrix[row][end] == target);
  };
};
;
int main() {
  Solution s;
  std::vector<std::vector<int>> matrix;
  matrix.push_back(vector<int>({1}));
  matrix.push_back(vector<int>({3}));
  matrix.push_back(vector<int>({5}));
  // matrix.push_back(vector<int>({1, 3}));
  // matrix.push_back(vector<int>({1, 3, 5, 7}));
  // matrix.push_back(vector<int>({10, 11, 16, 20}));
  // matrix.push_back(vector<int>({23, 30, 34, 60}));
  std::cout << s.searchMatrix(matrix, 5) << std::endl;
}  // @lc code=end
