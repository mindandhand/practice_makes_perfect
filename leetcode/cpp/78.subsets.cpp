/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  vector<vector<int>> ret;

 public:
  void findCombine(vector<int>& nums, vector<int>& data, int n, int k,
                   int pos) {
    for (size_t i = pos; i < n; ++i) {
      data.push_back(nums[i]);
      if (data.size() == k) {
        ret.push_back(data);
      } else {
        findCombine(nums, data, n, k, i + 1);
      }
      data.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    ret.push_back(vector<int>());
    for (size_t i = 1; i <= nums.size(); ++i) {
      vector<int> data;
      findCombine(nums, data, nums.size(), i, 0);
    }
    return ret;
  }
};
// @lc code=end
