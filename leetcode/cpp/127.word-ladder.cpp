/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int level = 0;
        std::unordered_set<std::string> members(wordList.begin(), wordList.end());
        std::queue<std::pair<std::string, int> > q;
        if (members.find(endWord) == members.end())
        {
            return 0;
        }
        q.push(make_pair(beginWord, 1));
        while (!q.empty())
        {
            auto convertStr = q.front().first;
            level = q.front().second;
            q.pop();
            for (auto i = 'a'; i <= 'z'; i++)
            {
                for (auto j = 0; j < convertStr.size(); ++j)
                {
                    if (i == convertStr[j])
                    {
                        continue;
                    }
                    auto newStr = convertStr;
                    newStr[j] = i;
                    if(newStr == endWord){
                        return level + 1;
                    }
                    if (members.find(newStr) != members.end())
                    {
                        q.push(make_pair(newStr, level + 1));
                        members.erase(newStr);
                    }
                }
            }
        }
        return 0;
    }
};

// int main()
// {
//     Solution s;
//     std::vector<std::string> wordList;
//     wordList.push_back("hot");
//     // wordList.push_back("vot");
//     wordList.push_back("dot");
//     wordList.push_back("dog");
//     wordList.push_back("lot");
//     wordList.push_back("log");
//     wordList.push_back("cog");
//     std::cout << s.ladderLength("hit", "cog", wordList) << std::endl;
// }
// @lc code=end
