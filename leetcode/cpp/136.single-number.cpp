/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include<iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
       for(int i = 1; i < nums.size(); ++i){
        ret = ret ^ nums[i];
       }
       return ret;
    }
};
// @lc code=end

