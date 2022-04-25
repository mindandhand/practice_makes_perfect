/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    auto ret = vector<vector<int>>(n, vector<int>(n, 1));
    std::pair<int, int> leftTop = std::make_pair(0, 0);
    std::pair<int, int> leftBottom = std::make_pair(n - 1, 0);
    std::pair<int, int> rightTop = std::make_pair(0, n - 1);
    std::pair<int, int> rightBottom = std::make_pair(n - 1, n - 1);
    int start = 1, end = n * n;
    while (start <= end) {
      if (leftTop.second == rightTop.second) {
        ret[leftTop.first][leftTop.second] = end;
        break;
      }
      for (int i = leftTop.second; i <= rightTop.second; ++i) {
        ret[leftTop.first][i] = start;
        ++start;
      }
      for (int i = rightTop.first + 1; i < rightBottom.first; ++i) {
        ret[i][rightTop.second] = start;
        ++start;
      }
      for (int i = rightBottom.second; i >= leftBottom.second; --i) {
        ret[leftBottom.first][i] = start;
        ++start;
      }
      for (int i = leftBottom.first - 1; i > leftTop.first; --i) {
        ret[i][leftBottom.second] = start;
        ++start;
      }
      ++leftTop.first;
      ++leftTop.second;
      ++leftBottom.second;
      --leftBottom.first;
      --rightBottom.first;
      --rightBottom.second;
      --rightTop.second;
      ++rightTop.first;
    }
    return ret;
  }
};
// @lc code=end
