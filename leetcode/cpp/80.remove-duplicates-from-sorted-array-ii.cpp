/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        int count = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[pos]){
                if(count == 1){
                    count = 2;
                    if(i != pos){
                        ++pos;
                        nums[pos] = nums[i];
                    } else {
                        ++pos;
                    }
                }  
            } else {
                if(i != pos){
                    ++pos;
                    nums[pos] = nums[i];
                    count = 1;
                }
            }
        }
        return pos + 1;
    }
};
// @lc code=end

