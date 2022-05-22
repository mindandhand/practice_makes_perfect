/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<bool>> accessed;
  bool findNextLetter(vector<vector<char>>& board, int i, int j,
                      vector<vector<bool>>& accessed, string word, int index) {
    if (index >= word.size()) return true;
    if (i > 0 && accessed[i - 1][j] == false &&
        board[i - 1][j] == word[index]) {
      if (index == word.size() - 1) {
        return true;
      }
      accessed[i - 1][j] = true;
      if (findNextLetter(board, i - 1, j, accessed, word, index + 1))
        return true;
      accessed[i - 1][j] = false;
    }
    if (j > 0 && accessed[i][j - 1] == false &&
        board[i][j - 1] == word[index]) {
      if (index == word.size() - 1) {
        return true;
      }
      accessed[i][j - 1] = true;
      if (findNextLetter(board, i, j - 1, accessed, word, index + 1))
        return true;
      accessed[i][j - 1] = false;
    }
    if (i < board.size() - 1 && accessed[i + 1][j] == false &&
        board[i + 1][j] == word[index]) {
      if (index == word.size() - 1) {
        return true;
      }
      accessed[i + 1][j] = true;
      if (findNextLetter(board, i + 1, j, accessed, word, index + 1))
        return true;
      accessed[i + 1][j] = false;
    }
    if (j < board[0].size() - 1 && accessed[i][j + 1] == false &&
        board[i][j + 1] == word[index]) {
      if (index == word.size() - 1) {
        return true;
      }
      accessed[i][j + 1] = true;
      if (findNextLetter(board, i, j + 1, accessed, word, index + 1))
        return true;
      accessed[i][j + 1] = false;
    }
    return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    accessed = vector<vector<bool>>(board.size(),
                                    vector<bool>(board[0].size(), false));
    for (auto i = 0; i < board.size(); ++i) {
      for (auto j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0]) {
          accessed[i][j] = true;
          if (findNextLetter(board, i, j, accessed, word, 1)) {
            return true;
          }
          accessed[i][j] = false;
        }
      }
    }
    return false;
  }
};

int main() {
  std::string word("ABCB");
  vector<vector<char>> data;
  data.push_back(vector<char>({'A', 'B', 'C', 'E'}));
  data.push_back(vector<char>({'S', 'F', 'C', 'S'}));
  data.push_back(vector<char>({'A', 'D', 'E', 'E'}));
  Solution s;
  std::cout << s.exist(data, word) << std::endl;
}
// @lc code=end
