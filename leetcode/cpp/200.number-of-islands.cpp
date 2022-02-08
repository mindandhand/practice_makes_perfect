/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ret = 0;
        if (grid.size() == 0)
        {
            return 0;
        }
        vector<vector<bool>> accessed = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1' && accessed[i][j] == false)
                {
                    queue<std::pair<int, int>> q;
                    ++ret;
                    q.push(std::make_pair(i, j));
                    accessed[i][j] = true;
                    while (!q.empty())
                    {
                        auto item = q.front();
                        q.pop();
                        
                        if (item.first - 1 >= 0 && grid[item.first - 1][item.second] == '1' && accessed[item.first - 1][item.second] == false)
                        {
                            accessed[item.first - 1][item.second] = true;
                            q.push(std::make_pair(item.first - 1, item.second));
                        }
                        if (item.second + 1 < grid[0].size() && grid[item.first][item.second + 1] == '1' && accessed[item.first][item.second + 1] == false)
                        {
                            accessed[item.first ][item.second+ 1] = true;
                            q.push(std::make_pair(item.first, item.second + 1));
                        }
                        if (item.first + 1 < grid.size() && grid[item.first + 1][item.second] == '1' && accessed[item.first + 1][item.second] == false)
                        {
                            accessed[item.first + 1][item.second] = true;
                            q.push(std::make_pair(item.first + 1, item.second));
                        }
                        if (item.second - 1 >= 0 && grid[item.first][item.second - 1] == '1' && accessed[item.first][item.second - 1] == false)
                        {
                            accessed[item.first][item.second - 1] = true;
                            q.push(std::make_pair(item.first, item.second - 1));
                        }
                    }
                }
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<vector<char>> test_data;
    test_data.push_back(vector<char>({'1','1','1','1','0'}));
    test_data.push_back(vector<char>({'1','1','0','1','0'}));
    test_data.push_back(vector<char>({'1','1','0','0','0'}));
    test_data.push_back(vector<char>({'0','0','0','0','0'}));
    std::cout << s.numIslands(test_data) << std::endl;
}
// @lc code=end
