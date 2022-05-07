/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> ret;

  void findCombine(vector<int>& data, int n, int k, int pos) {
    for (size_t i = pos; i < n; ++i) {
      data.push_back(i + 1);
      if (data.size() == k) {
        ret.push_back(data);
      } else {
        findCombine(data, n, k, i + 1);
      }
      data.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<int> data;
    findCombine(data, n, k, 0);
    return ret;
  }
};
int main() {
  Solution s;
  auto ret = s.combine(4, 2);
  for (size_t i = 0; i < ret.size(); ++i) {
    std::cout << std::endl;
    for (size_t j = 0; j < ret[i].size(); ++j) {
      std::cout << " " << ret[i][j];
    }
  }
}

// @lc code=end
