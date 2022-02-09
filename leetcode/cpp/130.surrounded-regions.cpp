/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
#include <vector>
#incude < queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0)
        {
            return;
        }
        vector<vector<bool>> accessed = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        std::queue<std::pair<int, int>> check_nodes;
        for (auto i = 0; i < board.size(); ++i)
        {
            check_nodes.push(std::make_pair(i, 0));
            check_nodes.push(std::make_pair(i, board[0].size() - 1));
        }
        for (auto i = 1; i < board[0].size() - 1; ++i)
        {
            check_nodes.push(std::make_pair(0, i));
            check_nodes.push(std::make_pair(board.size() - 1, i));
        }
        while (!check_nodes.empty())
        {
            auto check_node = check_nodes.front();
            check_nodes.pop();
            auto i = check_node.first;
            auto j = check_node.second;
            if (board[i][j] == 'O' && accessed[i][j] == false)
            {

                queue<std::pair<int, int>> q;
                q.push(std::make_pair(i, j));
                accessed[i][j] = true;
                while (!q.empty())
                {
                    auto item = q.front();
                    q.pop();

                    if (item.first - 1 >= 0 && board[item.first - 1][item.second] == 'O' && accessed[item.first - 1][item.second] == false)
                    {
                        accessed[item.first - 1][item.second] = true;
                        q.push(std::make_pair(item.first - 1, item.second));
                    }
                    if (item.second + 1 < board[0].size() && board[item.first][item.second + 1] == 'O' && accessed[item.first][item.second + 1] == false)
                    {
                        accessed[item.first][item.second + 1] = true;
                        q.push(std::make_pair(item.first, item.second + 1));
                    }
                    if (item.first + 1 < board.size() && board[item.first + 1][item.second] == 'O' && accessed[item.first + 1][item.second] == false)
                    {
                        accessed[item.first + 1][item.second] = true;
                        q.push(std::make_pair(item.first + 1, item.second));
                    }
                    if (item.second - 1 >= 0 && board[item.first][item.second - 1] == 'O' && accessed[item.first][item.second - 1] == false)
                    {
                        accessed[item.first][item.second - 1] = true;
                        q.push(std::make_pair(item.first, item.second - 1));
                    }
                }
            }
        }
        for (auto i = 0; i < board.size(); ++i)
        {
            for (auto j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'O' && accessed[i][j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end
