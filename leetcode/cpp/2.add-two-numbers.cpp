/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
#include <iostream>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        int tmp = 0;
        bool biggerThan9 = false;
        ListNode *l1Node = l1;
        ListNode *l2Node = l2;
        ListNode *remainNode = nullptr;
        ListNode *ret = nullptr;
        ListNode *retNode = ret;
        while (l1Node != nullptr && l2Node != nullptr)
        {
            tmp = l1Node->val + l2Node->val + (biggerThan9 ? 1 : 0);
            if (tmp > 9)
            {
                biggerThan9 = true;
                tmp %= 10;
            }
            else
            {
                biggerThan9 = false;
            }

            if (ret)
            {
                retNode->next = new ListNode(tmp);
                retNode = retNode->next;
            }
            else
            {
                ret = new ListNode(tmp);
                retNode = ret;
            }
            l1Node = l1Node->next;
            l2Node = l2Node->next;
        }
        remainNode = (l1Node == nullptr ? l2Node : l1Node);
        while (remainNode != nullptr)
        {
            tmp = (biggerThan9 ? 1 : 0) + remainNode->val;
            if (tmp > 9)
            {
                biggerThan9 = true;
                tmp %= 10;
            }
            else
            {
                biggerThan9 = false;
            }

            retNode->next = new ListNode(tmp);
            retNode = retNode->next;
            remainNode = remainNode->next;
        }
        if (biggerThan9)
        {
            retNode->next = new ListNode(1);
        }
        return ret;
    }
};
// @lc code=end
