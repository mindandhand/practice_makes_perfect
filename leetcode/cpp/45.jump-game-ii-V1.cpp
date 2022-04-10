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
  std::vector<bool> accessed;
  std::queue<std::vector<int>> paths;
  int jump(vector<int>& nums) {
    accessed = vector<bool>(nums.size(), false);
    accessed[0] = true;
    paths.push(std::vector<int>{0});
    while (paths.size() > 0) {
      auto item = paths.front();
      paths.pop();
      for (size_t i = 1; i <= nums[item[item.size() - 1]]; ++i) {
        if (i >= nums.size()) break;
        if (item[item.size() - 1] + i >= nums.size() - 1) {
          return item.size();
        }
        if (accessed[item[item.size() - 1] + i] == false) {
          std::vector<int> new_item(item);
          new_item.push_back(item[item.size() - 1] + i);
          accessed[item[item.size() - 1] + i] = true;
          paths.push(new_item);
        }
      }
    }
    return 0;
  }
};
// @lc code=end
