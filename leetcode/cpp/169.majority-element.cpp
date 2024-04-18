/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i){
            if(count == 0){
                val = nums[i];
                 count = 1;
            } else {
                if(nums[i] == val){
                    ++count;
                } else {
                    --count;
                }
            }
        }
        return val;
    }
};
// @lc code=end

