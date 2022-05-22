/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
  void findCombine(vector<int>& nums, vector<int>& data, int n, int k,
                   int pos) {
    for (size_t i = pos; i < n; ++i) {
      data.push_back(nums[i]);
      if (data.size() == k) {
        ret.push_back(data);
      } else {
        findCombine(nums, data, n, k, i + 1);
      }
      while (i < n - 1 && nums[i] == nums[i + 1]) ++i;
      data.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    ret.push_back(vector<int>());
    for (size_t i = 1; i <= nums.size(); ++i) {
      vector<int> data;
      findCombine(nums, data, nums.size(), i, 0);
    }
    return ret;
  }
};
// @lc code=end
