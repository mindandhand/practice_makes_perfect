/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  std::unordered_map<string, bool> cache;

 public:
  bool isInterleaveWithPos(string& s1, int pos1, string& s2, int pos2,
                           string& s3, int pos3) {
    if (pos3 >= s3.size()) {
      return true;
    }
    auto cache_key =
        std::to_string(pos1).append("_").append(std::to_string(pos2));
    if (cache.find(cache_key) != cache.end()) {
      return false;
    }
    if (pos1 < s1.size() && s1[pos1] == s3[pos3] &&
        isInterleaveWithPos(s1, pos1 + 1, s2, pos2, s3, pos3 + 1)) {
      return true;
    }
    if (pos2 < s2.size() && s2[pos2] == s3[pos3] &&
        isInterleaveWithPos(s1, pos1, s2, pos2 + 1, s3, pos3 + 1)) {
      return true;
    }
    cache[cache_key] = false;
    return false;
  }
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) {
      return false;
    }
    return isInterleaveWithPos(s1, 0, s2, 0, s3, 0);
  }
};

int main() {
  Solution s;
  std::cout << s.isInterleave("", "", "") << std::endl;
  std::cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
  std::cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << std::endl;
}
// @lc code=end
