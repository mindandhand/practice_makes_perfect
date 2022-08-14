/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        size_t i = 0, j = 0;
        unordered_set<char> cache;
        for (i = 0; i < board.size(); ++i)
        {
            cache.clear();
            for (j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.' && cache.find(board[i][j]) != cache.end())
                {
                    //std::cout << "r:" << i << ", h:" << j <<std::endl;
                    return false;
                }
                cache.insert(board[i][j]);
            }
        }
        for (i = 0; i < board[0].size(); ++i)
        {
            cache.clear();
            for (j = 0; j < board.size(); ++j)
            {
                if (board[j][i] != '.' && cache.find(board[j][i]) != cache.end())
                {
                    // std::cout << "r1:" << j << ", h1:" << i <<std::endl;
                    return false;
                }
                cache.insert(board[j][i]);
            }
        }

        for (i = 0; i < board.size() / 3; i = i + 1)
        {
            for (j = 0; j < board[i].size()/3; j = j + 1)
            {
                cache.clear();
                //std::cout <<"---------------" <<std::endl;
                for (size_t k = i * 3; k < i*3 + 3; ++k)
                {
                    for (size_t h = j * 3; h < j * 3+3; ++h)
                    {
                        if (board[k][h] != '.' && cache.find(board[k][h]) != cache.end())
                        {
                             //std::cout << "r2:" << k << ", h2:" << h << "," <<board[k][h] <<std::endl;
                            return false;
                        }
                        //std::cout << "i:" << k << ", j:"<< h << ","<< board[k][h]<<std::endl;
                        cache.insert(board[k][h]);
                    }
                }
            }
        }
        return true;
    }
};

// @lc code=end
