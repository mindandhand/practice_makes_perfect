/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

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
  void findQueenPostion(int& ret, int& n) {
    if (positions.size() == n) {
      return;
    }
    auto lineNumber = positions.size();
    for (auto i = 0; i < n; ++i) {
      if (canPutQueen(lineNumber, i)) {
        positions.push_back(std::make_pair(lineNumber, i));
        if (positions.size() == n) {
          ++ret;
        }
        accessed[lineNumber][i] = true;
        findQueenPostion(ret, n);
        accessed[lineNumber][i] = false;
        positions.pop_back();
      }
    }
  }

  int totalNQueens(int n) {
    int ret = 0;
    accessed = vector<vector<bool>>(n, vector<bool>(n, false));
    findQueenPostion(ret, n);
    return ret;
  }
};
// @lc code=end
