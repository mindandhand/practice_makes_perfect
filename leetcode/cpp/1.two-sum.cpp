/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> new_nums;
        int i = 0;
        while (i < nums.size())
        {
            new_nums.push_back(nums[i]);
            ++i;
        }
        std::sort(new_nums.begin(), new_nums.end());
        i = 0;
        int j = new_nums.size() - 1;
        while (i < j)
        {
            while (new_nums[i] + new_nums[j] < target)
                ++i;
            while (new_nums[i] + new_nums[j] > target)
                --j;
            if (new_nums[i] + new_nums[j] == target)
            {
                break;
            }
        }
        i = new_nums[i];
        j = new_nums[j];
        new_nums.clear();
        int k = 0;
        while (k < nums.size())
        {
            if (nums[k] == i)
            {
                new_nums.push_back(k);
                ++k;
                continue;
            }
            if (nums[k] == j)
                new_nums.push_back(k);
            if (new_nums.size() == 2)
            {
                break;
            }
            ++k;
        }
        return new_nums;
    }
};
// @lc code=end
