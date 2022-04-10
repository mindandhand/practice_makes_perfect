/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int reach = 0;
    for (size_t i = 0; i < nums.size() && i <= reach; ++i) {
      if (reach >= nums.size() - 1) return true;
      if (nums[i] + i > reach) {
        reach = nums[i] + i;
      }
    }
    return false;
  }
};
// @lc code=end
