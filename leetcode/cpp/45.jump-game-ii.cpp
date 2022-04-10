/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
#include <iostream>
#include <queue>
#include <vector>
// @lc code=start
using namespace std;
class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() <= 1) return 0;
    int current_max = nums[0];
    int new_max = 0 + current_max, pos = 0, level = 1;
    while (pos < nums.size()) {
      if (current_max >= nums.size() - 1) {
        return level;
      }
      ++level;
      for (size_t i = pos + 1; i <= current_max; ++i) {
        if (nums[i] + i > new_max) {
          new_max = nums[i] + i;
        }
      }
      pos = current_max;
      current_max = new_max;
    }
    return 0;
  }
};
// @lc code=end
