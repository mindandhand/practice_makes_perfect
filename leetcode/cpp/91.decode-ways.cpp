/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int ret;
  std::unordered_map<int, int> cache;
  void findDecode(string &s, int pos) {
    if (pos < 0) {
      ++ret;
      return;
    }
    int cache_num = cache[pos];
    if (cache_num != 0) {
      ret = ret + cache_num;
      return;
    }
    if (s[pos] != '0') {
      findDecode(s, pos - 1);
    }
    if (pos > 0) {
      if (s[pos - 1] == '0') return;
      if (s[pos - 1] >= '3' || (s[pos - 1] == '2' && s[pos] >= '7')) {
        return;
      }
      findDecode(s, pos - 2);
    }
    cache[pos] = ret;
  }
  int numDecodings(string s) {
    ret = 0;
    findDecode(s, s.size() - 1);
    return ret;
  }
};
int main() {
  Solution s;
  std::cout << s.numDecodings("12") << std::endl;
}
// @lc code=end
