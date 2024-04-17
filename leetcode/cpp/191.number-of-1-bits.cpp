/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
#include<iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingWeight(int n) {
        int ret = 0;
        while ( n > 0 ){
            n = n& (n - 1 );
            ret = ret + 1;
        }
        return ret;
        
    }
};
// @lc code=end

