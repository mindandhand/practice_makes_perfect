/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> ret;
  void restoreIpAddr(string &s, int pos, vector<int> curElement) {
    if (curElement.size() >= 4) {
      if (pos > s.size() - 1 && curElement.size() == 4) {
        std::string ip;
        for (int i = 0; i < 3; i++) {
          ip.append(std::to_string(curElement[i])).append(".");
        }
        ip.append(std::to_string(curElement[3]));
        ret.push_back(ip);
        std::cout << "ip:" << ip << std::endl;
      }
      if (curElement.size() == 4 && curElement[curElement.size() - 1] < 26) {
      } else {
        return;
      }
    }
    if (pos > s.size() - 1) {
      return;
    }
    if (curElement.size() == 0) {
      curElement.push_back(s[pos] - '0');
      restoreIpAddr(s, pos + 1, curElement);
    } else {
      auto val = curElement[curElement.size() - 1];
      if (val == 0) {
        curElement.push_back(s[pos] - '0');
        restoreIpAddr(s, pos + 1, curElement);
      } else {
        {
          curElement.push_back(s[pos] - '0');
          restoreIpAddr(s, pos + 1, curElement);
          curElement.pop_back();
        }
        if (val * 10 + (s[pos] - '0') < 256) {
          curElement[curElement.size() - 1] = val * 10 + (s[pos] - '0');
          restoreIpAddr(s, pos + 1, curElement);
        }
      }
    }
  }
  vector<string> restoreIpAddresses(string s) {
    if (s.empty()) {
      return ret;
    }
    vector<int> curElement;
    restoreIpAddr(s, 0, curElement);
    return ret;
  }
};
int main() {
  Solution s;
  auto ret = s.restoreIpAddresses("101023");
  for (auto i = 0; i < ret.size(); i++) {
    std::cout << ret[i] << std::endl;
  }
}
// @lc code=end
