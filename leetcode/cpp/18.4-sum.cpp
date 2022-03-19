/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() < 4) return ret;
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    for (auto i = 0; i < nums.size(); ++i) std::cout << nums[i] << " ";
    std::cout << std::endl;
    for (auto i1 = 0; i1 < nums.size() - 3; ++i1) {
      if (i1 > 0 && nums[i1] == nums[i1 - 1]) {
        continue;
      }
      for (auto i2 = i1 + 1; i2 < nums.size() - 2; ++i2) {
        if (i2 > i1 + 1 && nums[i2] == nums[i2 - 1]) {
          continue;
        }
        if (nums[i1] + nums[i2] < target - nums[n - 2] - nums[n - 1]) {
          continue;
        }
        if (nums[i1] + nums[i2] > target - nums[i2 + 1] - nums[i2 + 2]) {
          break;
        }
        for (auto i3 = i2 + 1; i3 < nums.size() - 1; ++i3) {
          if (i3 > i2 + 1 && nums[i3] == nums[i3 - 1]) {
            continue;
          }
          for (auto i4 = i3 + 1; i4 < nums.size(); ++i4) {
            if (i4 > i3 + 1 && nums[i4] == nums[i4 - 1]) {
              continue;
            }
            if (nums[i1] + nums[i2] + nums[i3] + nums[i4] == target) {
              vector<int> new_qr = {nums[i1], nums[i2], nums[i3], nums[i4]};
              ret.push_back(new_qr);
            }
          }
        }
      }
    }
    return ret;
  }
};
int main() {
  // std::vector<int> nums = {1, 0, -1, 0, -2, 2};
  std::vector<int> nums = {2, 2, 2, 2, 2};
  Solution s;
  auto ret = s.fourSum(nums, 8);

  for (auto i = 0; i < ret.size(); ++i) {
    std::cout << std::endl;
    for (auto j = 0; j < ret[i].size(); ++j) {
      std::cout << " " << ret[i][j];
    }
  }
  std::cout << std::endl;
}
// @lc code=end
