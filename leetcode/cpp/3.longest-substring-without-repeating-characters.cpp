/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int loop = 1;
        int pos = 0;
        int max_len = 1;
        int len = 1;
        int i = 0;
        bool find = false;
        while (loop < s.size())
        {
            i = 0;
            find = false;
            while (i < len)
            {
                if (s[loop] == s[pos + i])
                {
                    pos = pos + i + 1;
                    len = loop - pos + 1;
                    ++loop;
                    find = true;
                    break;
                }
                ++i;
            }
            if(find == true){
                continue;
            }
            ++len;
            ++loop;
            if (len > max_len){ 
                max_len = len;
            }
                
        }
        return max_len;
    }
};
// @lc code=end
