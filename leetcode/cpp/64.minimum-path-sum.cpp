/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  std::unordered_map<int, std::unordered_map<int, int>> cache;
  int findPath(vector<vector<int>>& grid, int startm, int startn) {
    int ret = 0, tmp_sum = INT32_MAX;
    if (cache[startm].find(startn) != cache[startm].end()) {
      return cache[startm][startn];
    }
    if (startm == grid.size() - 1 && startn == grid[0].size() - 1) {
      cache[startm][startn] = grid[startm][startn];
      return grid[startm][startn];
    }
    if (startm < grid.size() - 1) {
      auto tmp = grid[startm][startn] + findPath(grid, startm + 1, startn);
      if (tmp < tmp_sum) {
        tmp_sum = tmp;
      }
    }
    if (startn < grid[0].size() - 1) {
      auto tmp = grid[startm][startn] + findPath(grid, startm, startn + 1);
      if (tmp < tmp_sum) {
        tmp_sum = tmp;
      }
    }
    std::cout << "startm " << startm << ", startn:" << startn
              << "  cache:" << tmp_sum << std::endl;
    cache[startm][startn] = tmp_sum;
    return tmp_sum;
  }
  int minPathSum(vector<vector<int>>& grid) { return findPath(grid, 0, 0); }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> vec;
  vec.push_back(vector<int>({1, 2, 3}));
  vec.push_back(vector<int>({4, 5, 6}));
  //   vec.push_back(vector<int>({4, 2, 1}));
  // vec.push_back(vector<int>({5, 1}));
  // vec.push_back(vector<int>({2, 1}));

  std::cout << s.minPathSum(vec) << std::endl;
}
// @lc code=end
