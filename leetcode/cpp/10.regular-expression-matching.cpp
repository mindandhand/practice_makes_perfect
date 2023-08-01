/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatchWithPosition(string & s, int i, string &p, int j){
        if(i >= s.size() && j >= p.size()){
            return true;
        }
        if(s[i] == p[j]){
            return isMatchWithPosition(s, i + 1, p, j+ 1);
        } else if (p[j] == '.'){

        } else if (p[j] == '*'){

        }
    }
    bool isMatch(string s, string p) {
       return isMatchWithPosition(s, 0, p, 0);
    }
};
// @lc code=end

