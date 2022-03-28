/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    std::vector<char> answer;
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int32_t tmp, pos1, add, low, high;
    for (auto i = 0; i < num1.size(); ++i) {
      for (auto j = 0; j < num2.size(); ++j) {
        pos1 = i + j;
        tmp = (num1[i] - '0') * (num2[j] - '0');
        low = tmp % 10;
        high = tmp / 10;
        if (pos1 < answer.size() && low + answer[pos1] - '0' > 9) {
          high = high + 1;
          answer[pos1] = low + answer[pos1] - 10;
        } else if (pos1 < answer.size()) {
          answer[pos1] = low + answer[pos1];
        } else {
          answer.push_back(low + '0');
        }
        while (high > 0) {
          ++pos1;
          tmp = 0;
          if (pos1 < answer.size() && high + answer[pos1] - '0' > 9) {
            tmp = 1;
            answer[pos1] = high + answer[pos1] - 10;
          } else if (pos1 < answer.size()) {
            answer[pos1] = high + answer[pos1];
          } else {
            answer.push_back(high + '0');
          }
          high = tmp;
        }
      }
    }
    while (answer.size() > 1 && answer[answer.size() - 1] == '0') {
      answer.pop_back();
    }
    std::reverse(answer.begin(), answer.end());
    return std::string(answer.begin(), answer.end());
  }
};
int main() {
  Solution s;
  std::cout << s.multiply("200", "300") << std::endl;
}
// @lc code=end
