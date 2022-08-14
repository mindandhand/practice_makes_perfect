/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int ret = 0;
        for(int i = 0; i < n; i++){
            ret =ret +  numTrees(i) * numTrees(n - i - 1);
        }
        return ret; 
    }
};
// @lc code=end

