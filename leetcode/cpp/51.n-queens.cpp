/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<bool>> accessed;
  vector<std::pair<int, int>> positions;
  bool canPutQueen(int lineNumber, int rolNumber) {
    auto i = lineNumber;
    while (i >= 0) {
      if (accessed[i][rolNumber] == true) return false;
      --i;
    }
    auto j = rolNumber;
    while (j >= 0) {
      if (accessed[lineNumber][j] == true) return false;
      --j;
    }
    i = lineNumber;
    j = rolNumber;
    while (i >= 0 && j >= 0) {
      if (accessed[i][j] == true) return false;
      --j;
      --i;
    }
    i = lineNumber;
    j = rolNumber;
    while (i >= 0 && j < accessed[0].size()) {
      if (accessed[i][j] == true) return false;
      ++j;
      --i;
    }
    return true;
  }
  void findQueenPostion(vector<vector<string>>& ret, int& n) {
    if (positions.size() == n) {
      return;
    }
    auto lineNumber = positions.size();
    for (auto i = 0; i < n; ++i) {
      if (canPutQueen(lineNumber, i)) {
        positions.push_back(std::make_pair(lineNumber, i));
        if (positions.size() == n) {
          string default_val;
          for (auto j = 0; j < n; ++j) {
            default_val.append(".");
          }
          std::vector<std::string> new_queues_position;
          for (auto k = 0; k < positions.size(); ++k) {
            auto line_element = default_val;
            line_element[positions[k].second] = 'Q';
            new_queues_position.push_back(line_element);
          }
          ret.push_back(new_queues_position);
        }
        accessed[lineNumber][i] = true;
        findQueenPostion(ret, n);
        accessed[lineNumber][i] = false;
        positions.pop_back();
      }
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    accessed = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<vector<string>> ret;
    findQueenPostion(ret, n);
    return ret;
  }
};

int main() {
  Solution s;
  auto ret = s.solveNQueens(4);
  for (auto i = 0; i < ret.size(); ++i) {
    std::cout << "solution " << i << " :" << std::endl;
    for (auto j = 0; j < ret[0].size(); ++j) {
      std::cout << ret[i][j] << std::endl;
    }
  std:
    cout << "===================" << std::endl;
  }
}
// @lc code=end
