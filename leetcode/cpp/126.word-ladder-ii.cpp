/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
#include <queue>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int minLength = 2000;
        int level = 1;
        std::vector<std::vector<string>> ret;
        unordered_set<std::string> members(wordList.begin(), wordList.end());
        if (members.find(endWord) == members.end())
        {
            return ret;
        }

        std::queue<vector<string>> q;
        vector<string> root;
        root.push_back(beginWord);
        q.push(root);
        unordered_set<string> words;
        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            auto orginStr = item.back();
            if (item.size() > level)
            {
                for (auto w : words)
                    members.erase(w);
                words.clear();
                if (item.size() > minLength)
                {
                    break;
                }
                else
                    level = item.size();
            }
            for (auto ch = 'a'; ch <= 'z'; ++ch)
            {
                for (auto i = 0; i < orginStr.size(); ++i)
                {
                    auto newStr = orginStr;
                    newStr[i] = ch;
                    if (newStr == orginStr)
                    {
                        continue;
                    }
                    auto newVec = item;
                    newVec.push_back(newStr);
                    words.insert(newStr);
                    if (newStr == endWord)
                    {
                        ret.push_back(newVec);
                        minLength = item.size();
                    }
                    if (members.find(newStr) != members.end())
                    {
                        q.push(newVec);
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
    std::vector<std::string> wordList;
    wordList.push_back("hot");
    // wordList.push_back("vot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    auto paths = s.findLadders("hit", "cog", wordList);
    for (int i = 0; i < paths.size(); ++i)
    {
        for (int j = 0; j < paths[i].size(); ++j)
        {
            std::cout << paths[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// @lc code=end
