/*
 * @Author: mindandhand 1639545667@qq.com
 * @Date: 2023-07-25 08:21:37
 * @LastEditors: mindandhand 1639545667@qq.com
 * @LastEditTime: 2023-07-25 12:28:03
 * @FilePath: /practice_makes_perfect/leetcode/cpp/75.sort-colors.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    if (nums.size() <= 1) return;
    int lt_pos = 0, eq_pos = 0, gt_pos = nums.size() - 1;

    while (eq_pos <= gt_pos) {
      while (lt_pos <= gt_pos && nums[lt_pos] < 1) {
        ++lt_pos;
      }

      if (eq_pos <= lt_pos) eq_pos = lt_pos;
      while (eq_pos <= gt_pos && nums[eq_pos] == 1) {
        ++eq_pos;
      }
      while (gt_pos >= 0 && nums[gt_pos] > 1) --gt_pos;
      //   for (size_t i = 0; i < nums.size(); ++i) {
      //     std::cout << nums[i] << " ";
      //   }
      //   std::cout << std::endl;
      if (eq_pos > gt_pos) {
        return;
      }
      if (nums[gt_pos] == 1) {
        swap(nums[gt_pos], nums[eq_pos]);
      } else if (nums[gt_pos] == 0) {
        swap(nums[gt_pos], nums[lt_pos]);
      }
    }
  }
};

// int main() {
//   vector<int> vec{2, 0, 2, 1, 1, 0};
//   // vector<int> vec{2, 0, 1};
//   Solution s;
//   for (size_t i = 0; i < vec.size(); ++i) {
//     std::cout << vec[i] << " ";
//   }
//   std::cout << std::endl;
//   s.sortColors(vec);
//   std::cout << "==========================" << std::endl;
//   for (size_t i = 0; i < vec.size(); ++i) {
//     std::cout << vec[i] << " ";
//   }
//   std::cout << std::endl;
// }
// @lc code=end
