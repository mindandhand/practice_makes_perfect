/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret;
    unordered_map<std::string, int> dict;
    for (auto str : strs) {
      std::string new_str(str);
      std::sort(new_str.begin(), new_str.end());
      if (dict.find(new_str) == dict.end()) {
        ret.push_back(std::vector<std::string>{str});
        dict[new_str] = ret.size() - 1;
      } else {
        ret[dict[new_str]].push_back(str);
      }
    }
    return ret;
  }
};
// @lc code=end
