/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    uint64_t rows[4] = {0};
    uint64_t cols[4] = {0};
    int tmp_mul, tmp_p;
    uint64_t pos;

    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          tmp_mul = i / 64;
          tmp_p = i % 64;
          pos = 1;
          pos = pos << tmp_p;
          rows[tmp_mul] = rows[tmp_mul] | pos;
          tmp_mul = j / 64;
          tmp_p = j % 64;
          pos = 1;
          pos = pos << tmp_p;
          cols[tmp_mul] = cols[tmp_mul] | pos;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      pos = 1;
      auto row_number = i * 64;
      for (int j = 0; j < 64 && row_number + j < matrix.size(); j++) {
        if (j != 0) {
          pos = pos << 1;
        }
        if (pos & rows[i]) {
          matrix[row_number + j] = vector<int>(matrix[0].size(), 0);
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      pos = 1;
      auto col_number = i * 64;
      for (int j = 0; j < 64 && col_number + j < matrix[0].size(); j++) {
        if (j != 0) {
          pos = pos << 1;
        }
        if (pos & cols[i]) {
          auto row_pos = i * 64 + j;
          for (size_t k = 0; k < matrix.size(); ++k) matrix[k][row_pos] = 0;
        }
      }
    }
  }
};
int main() {
  Solution s;
  std::vector<std::vector<int>> matrix;
  matrix.push_back(vector<int>({9, 1, 3, 0, 1, 5, 7, 4, 1}));
  matrix.push_back(vector<int>({2, 2, 5, 2, 5, 4, 4, 3, 8}));
  matrix.push_back(vector<int>({4, 9, 7, 0, 3, 6, 9, 5, 9}));
  matrix.push_back(vector<int>({4, 1, 8, 8, 4, 1, 5, 7, 6}));
  std::cout << "before:" << std::endl;
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  s.setZeroes(matrix);
  std::cout << "after:" << std::endl;
  for (size_t i = 0; i < matrix.size(); ++i) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
// @lc code=end
