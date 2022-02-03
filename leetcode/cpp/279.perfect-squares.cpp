/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <queue>
#include <iostream>

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(n, 0));
        int ret = 0;
        std::vector<bool> visited = std::vector<bool>(n + 1, false);
        std::vector<int> cache = std::vector<int>(n + 1, 0);
        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            if (item.first == 0)
            {
                ret = item.second;
                break;
            }
            for (auto i = 1; item.first - i * i >= 0; ++i)
            {
                int tmp = item.first - i * i;
                if (!visited[tmp])
                {
                    q.push(std::make_pair(tmp, visited[tmp] + item.second + 1));
                    visited[tmp] = true;
                }
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    // std::cout << "7:" << s.numSquares(7) << std::endl;
    std::cout << "18:" << s.numSquares(18) << std::endl;
    // std::cout << "4:" << s.numSquares(4) << std::endl;
}
// @lc code=end
