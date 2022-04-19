/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
bool compare(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}
// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ret;
    std::sort(intervals.begin(), intervals.end(), compare);
    vector<int> tmp;
    for (size_t i = 0; i < intervals.size(); ++i) {
      if (tmp.size() == 0) {
        tmp.insert(tmp.begin(), intervals[i].begin(), intervals[i].end());
        continue;
      }
      if (intervals[i][0] <= tmp[1]) {
        if (tmp[1] < intervals[i][1]) {
          tmp[1] = intervals[i][1];
        }
      } else {
        ret.push_back(tmp);
        tmp.clear();
        tmp.insert(tmp.begin(), intervals[i].begin(), intervals[i].end());
      }
    }
    ret.push_back(tmp);
    return ret;
  }
};
void printVec(vector<vector<int>> dVec) {
  for (size_t i = 0; i < dVec.size(); ++i) {
    for (size_t j = 0; j < dVec[i].size(); ++j) {
      std::cout << dVec[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  vector<vector<int>> vec;
  vec.push_back(vector<int>({1, 3}));
  vec.push_back(vector<int>({2, 6}));
  vec.push_back(vector<int>({8, 10}));
  vec.push_back(vector<int>({18, 19}));
  printVec(vec);
  std::cout << "----------------------------------" << std::endl;
  Solution s;
  auto res = s.merge(vec);
  printVec(vec);
  std::cout << "==================================" << std::endl;
  printVec(res);
  return 0;
}
// @lc code=end
