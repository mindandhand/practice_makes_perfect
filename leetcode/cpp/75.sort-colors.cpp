/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int lt = -1, gt = nums.size() - 1, pos = 0;
    while (pos <= gt) {
      while (gt >= 0 && nums[gt] == 2) --gt;
      if (gt < 0) break;
      if (nums[pos] > 1) {
        swap(nums[gt], nums[pos]);
      } else if (nums[pos] == 1) {
        ++pos;
      } else {
        // == 0
        swap(nums[lt + 1], nums[pos]);
        ++lt;
        ++pos;
      }
    }
  }
};

int main() {
  vector<int> vec{2, 0, 2, 1, 1, 0};
  // vector<int> vec{2, 0, 1};
  Solution s;
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  s.sortColors(vec);
  std::cout << "==========================" << std::endl;
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}
// @lc code=end
