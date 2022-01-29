/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        std::cout << lists.size() << std::endl;
        int nullNumber = 0;
        ListNode *ret = nullptr, *cur;
        int i{0};
        int smallestIndex = 0;
        while (nullNumber < lists.size())
        {
            i = 0;
            for (; i < lists.size(); i++)
            {
                if (lists[i] != nullptr)
                {
                    smallestIndex = i;
                    break;
                }
            }
            i = smallestIndex + 1;
            for (; i < lists.size(); i++)
            {
                if (lists[i] != nullptr && lists[i]->val < lists[smallestIndex]->val)
                {
                    smallestIndex = i;
                }
            }
            if (ret == nullptr)
            {
                ret = lists[smallestIndex];
                cur = ret;
            }
            else if (lists[smallestIndex] != nullptr)
            {
                cur->next = lists[smallestIndex];
                cur = cur->next;
            }

            if (lists[smallestIndex] == nullptr || lists[smallestIndex]->next == nullptr)
            {
                ++nullNumber;
                if (nullNumber == lists.size())
                {
                    return ret;
                }
            }
            if (lists[smallestIndex] != nullptr)
                lists[smallestIndex] = lists[smallestIndex]->next;
        }
        return ret;
    }
};
// @lc code=end
