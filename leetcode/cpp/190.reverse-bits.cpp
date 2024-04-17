/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */
#include <iostream>
// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
         uint32_t ret = 0;
        while(i < 31){
            if(n & 0x1){
                ret = ret + 1;
            }
            n = n >> 1;
            ret = ret << 1;
            ++i;
        }
        if(n & 0x1){
                ret = ret + 1;
            }
        return ret;
    }
};
// @lc code=end

