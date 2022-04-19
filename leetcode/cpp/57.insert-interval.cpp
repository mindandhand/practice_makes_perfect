/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int start_pos = -1;
    for (size_t i = 0; i < intervals.size(); ++i) {
      if (newInterval[0] > intervals[i][1]) {
        continue;
      }
      if (newInterval[1] < intervals[i][0]) {
        intervals.insert(intervals.begin() + i, newInterval);
        return intervals;
      } else {
        start_pos = i;
        break;
      }
    }
    if (start_pos == -1) {
      intervals.push_back(newInterval);
      return intervals;
    }
    auto end_pos = start_pos;
    for (size_t i = start_pos + 1; i < intervals.size(); ++i) {
      if (intervals[i][0] > newInterval[1]) {
        end_pos = i - 1;
        break;
      }
      if (newInterval[1] > intervals[i][1]) {
        if (i == intervals.size() - 1) end_pos = i;
        continue;
      }
      end_pos = i;
      break;
    }
    if (newInterval[0] > intervals[start_pos][0])
      newInterval[0] = intervals[start_pos][0];
    if (newInterval[1] < intervals[end_pos][1])
      newInterval[1] = intervals[end_pos][1];
    intervals.erase(intervals.begin() + start_pos,
                    intervals.begin() + end_pos + 1);
    intervals.insert(intervals.begin() + start_pos, newInterval);
    return intervals;
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
  vec.push_back(vector<int>({0, 2}));
  vec.push_back(vector<int>({3, 9}));
  // vec.push_back(vector<int>({8, 10}));
  printVec(vec);
  auto newVec = vector<int>({6, 8});
  std::cout << "----------------------------------" << std::endl;
  Solution s;
  auto res = s.insert(vec, newVec);
  std::cout << "==================================" << std::endl;
  printVec(res);
  return 0;
}
// @lc code=end
