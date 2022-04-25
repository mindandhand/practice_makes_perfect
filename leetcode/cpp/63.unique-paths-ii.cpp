/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
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

  int findPath(vector<vector<int>>& obstacleGrid, int startm, int startn) {
    int ret = 0;
    if (obstacleGrid[startm][startn] == 1) {
      return ret;
    }
    if (cache[startm].find(startn) != cache[startm].end()) {
      return cache[startm][startn];
    }
    if (startm == obstacleGrid.size() - 1 &&
        startn == obstacleGrid[0].size() - 1) {
      cache[startm][startn] = 1;
      return 1;
    }
    if (startm < obstacleGrid.size() - 1) {
      ret += findPath(obstacleGrid, startm + 1, startn);
    }
    if (startn < obstacleGrid[0].size() - 1) {
      ret += findPath(obstacleGrid, startm, startn + 1);
    }
    cache[startm][startn] = ret;
    return ret;
  }
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    return findPath(obstacleGrid, 0, 0);
  }
};
int main() {
  Solution s;
  std::vector<std::vector<int>> vec;
  vec.push_back(vector<int>({0, 0, 0}));
  vec.push_back(vector<int>({0, 1, 0}));
  vec.push_back(vector<int>({0, 0, 0}));
  std::cout << s.uniquePathsWithObstacles(vec) << std::endl;
}
// @lc code=end
