/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include <vector>
// @lc code=start
class Solution {
public:
      int lengthOfLIS(vector<int> &nums)
    {
         std::vector<int> lengthLIS = std::vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (nums[i] > nums[j])
                {
                    if(lengthLIS[j] + 1 > lengthLIS[i])
                        lengthLIS[i] = lengthLIS[j] + 1;
                }
                
                --j;
            }
        }
        int ret = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (lengthLIS[i] > ret)
                ret = lengthLIS[i];
        }
        return ret;
    }
};

// @lc code=end
