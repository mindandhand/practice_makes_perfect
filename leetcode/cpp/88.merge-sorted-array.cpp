/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int loop = m + n - 1;
        while(m > 0 || n > 0){
            if (m > 0 && n > 0){
                if(nums1[m-1] < nums2[n - 1]){
                    nums1[loop] = nums2[n - 1];
                    --n;
                }
                    
                else {
                    nums1[loop] = nums1[m - 1];
                    --m;
                }
                    
            } else if (n > 0){
               nums1[loop] = nums2[n - 1];
                    --n; 
            } else {
                --m;
            }
            --loop;
        }
    }
};
// @lc code=end

