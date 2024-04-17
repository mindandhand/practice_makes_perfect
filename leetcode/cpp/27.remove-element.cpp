/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        int i = 0;
        for(; i < nums.size(); i++){
            if(nums[i] != val){
                if(pos != i){
                    nums[pos] = nums[i];   
                }
                ++pos;
            }
        }
        return pos;
    }
};
// @lc code=end

