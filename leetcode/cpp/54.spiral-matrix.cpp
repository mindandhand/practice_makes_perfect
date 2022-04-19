/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    auto ret = vector<int>();
    std::pair<int, int> leftTop = std::make_pair(0, 0);
    std::pair<int, int> rightTop = std::make_pair(0, matrix[0].size() - 1);
    std::pair<int, int> leftBottom = std::make_pair(matrix.size() - 1, 0);
    std::pair<int, int> rightBottom =
        std::make_pair(matrix.size() - 1, matrix[0].size() - 1);
    auto totol_num = matrix.size() * matrix[0].size();
    while (ret.size() < totol_num) {
      if (leftTop.second <= rightTop.second) {
        for (auto i = leftTop.second; i <= rightTop.second; ++i) {
          ret.push_back(matrix[leftTop.first][i]);
        }
      }
      if (rightTop.first < rightBottom.first) {
        for (auto i = rightTop.first + 1; i < rightBottom.first; ++i) {
          ret.push_back(matrix[i][rightTop.second]);
        }
      }
      if (rightBottom.first > leftTop.first &&
          rightBottom.second >= leftBottom.second) {
        for (auto i = rightBottom.second; i >= leftBottom.second; --i) {
          ret.push_back(matrix[rightBottom.first][i]);
        }
      }
      if (leftBottom.second < rightBottom.second &&
          leftBottom.first > leftTop.first) {
        for (auto i = leftBottom.first - 1; i > leftTop.first; --i) {
          ret.push_back(matrix[i][leftBottom.second]);
        }
      }
      ++leftTop.first;
      ++leftTop.second;
      ++rightTop.first;
      --rightTop.second;
      --leftBottom.first;
      ++leftBottom.second;
      --rightBottom.first;
      --rightBottom.second;
    }
    return ret;
  }
};

// @lc code=end
