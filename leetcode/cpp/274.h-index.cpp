/*
 * @Author: mindandhand 1639545667@qq.com
 * @Date: 2023-07-28 10:39:51
 * @LastEditors: mindandhand 1639545667@qq.com
 * @LastEditTime: 2023-07-28 14:43:48
 * @FilePath: /practice_makes_perfect/leetcode/cpp/274.h-index.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int min_val = *min_element(citations.begin(), citations.end());
    int max_val = *max_element(citations.begin(), citations.end());
    std::vector<int> countStat(max_val - min_val + 1, 0);
    for (int i = 0; i < citations.size(); ++i) {
      ++countStat[citations[i] - min_val];
    }
    int articalNum = 0;
    for (int i = countStat.size() - 1; i >= 0; --i) {
      articalNum = articalNum + countStat[i];
      if (articalNum >= min_val + i) {
        return min_val + i;
      }
    }
    return articalNum;
  }
};
// @lc code=end
