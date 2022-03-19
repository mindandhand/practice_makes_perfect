/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
#include <algorithm>
#include <iostream>
#include <vector>
// @lc code=start
class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    if (nums.size() <= 1) {
      return;
    }
    auto last_sort_pos = nums.size() - 1;
    while (last_sort_pos >= 1 && nums[last_sort_pos - 1] >= nums[last_sort_pos])
      --last_sort_pos;
    if (last_sort_pos == 0) {
      std::reverse(nums.begin(), nums.end());
      return;
    } else {
      auto swap_pos = nums.size() - 1;
      while (swap_pos > 0 && nums[swap_pos] <= nums[last_sort_pos - 1])
        --swap_pos;
      if (swap_pos < last_sort_pos) {
        return;
      }
      std::swap(nums[swap_pos], nums[last_sort_pos - 1]);
      std::sort(nums.begin() + last_sort_pos, nums.end());
    }
    return;
  }
};
void print(std::vector<int>& nums) {
  for (auto i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
int main() {
  // std::vector<int> testVec{1, 2, 3};
  std::vector<int> testVec{5, 1, 1};
  //  std::vector<int> testVec{3, 2, 1};
  //   std::vector<int> testVec{1, 5, 1};
  print(testVec);
  Solution s;
  s.nextPermutation(testVec);
  print(testVec);
}

// @lc code=end
