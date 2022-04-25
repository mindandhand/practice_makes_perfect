/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
 public:
  int findPath(int m, int n, int startm, int startn) {
    int ret = 0;
    if (startm == m && startn == n) {
      return 1;
    }
    if (startm < m) {
      ret += findPath(m, n, startm + 1, startn);
    }
    if (startn < n) {
      ret += findPath(m, n, startm, startn + 1);
    }
    return ret;
  }
  int uniquePaths(int m, int n) { return findPath(m, n, 1, 1); }
};
int main() {
  Solution s;

  std::cout << s.uniquePaths(23, 12) << std::endl;
}
// @lc code=end
