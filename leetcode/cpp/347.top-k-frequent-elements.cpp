/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;
// @lc code=start

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ret;
        if (k == 0 || nums.size() == 0)
        {
            return ret;
        }
        std::unordered_map<int, int> freqMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++freqMap[nums[i]];
        }

        priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, greater<std::pair<int, int> > > pq;

        for (auto iter = freqMap.begin(); iter != freqMap.end(); ++iter)
        {
            if (pq.size() < k)
            {
                pq.push(std::make_pair(iter->second, iter->first));
            }
            else
            {
                if (iter->second > pq.top().first)
                {
                    pq.pop();
                    pq.push(std::make_pair(iter->second, iter->first));
                }
            }
        }
        while (pq.size() > 0)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 2, 2, 3};
    Solution s;
    auto ret = s.topKFrequent(nums, 2);
    std::cout << "size of top 2:" << ret.size() << std::endl;
    for (int i : ret)
    {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;
}
// @lc code=end
