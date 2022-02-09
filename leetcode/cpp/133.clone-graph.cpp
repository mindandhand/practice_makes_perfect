/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
#include <queue>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (nullptr == node)
        {
            return node;
        }
        unordered_set<Node *> accessed;
        unordered_map<int, Node *> origin_dict;
        unordered_map<int, Node *> dict;
        queue<Node *> q;
        q.push(node);
        while (!q.empty())
        {
            auto item = q.front();
            q.pop();
            accessed.insert(item);
            origin_dict[item->val] = item;
            for (int i = 0; i < item->neighbors.size(); ++i)
            {
                if (accessed.find(item->neighbors[i]) == accessed.end())
                {
                    q.push(item->neighbors[i]);
                }
            }
        }
        for (int i = 1; i <= origin_dict.size(); ++i)
        {
            dict[i] = new Node(i);
        }
        for (int i = 1; i <= origin_dict.size(); ++i)
        {

            auto item = origin_dict[i];
            auto copy_item = dict[i];
            for (int i = 0; i < item->neighbors.size(); ++i)
            {
                copy_item->neighbors.push_back(dict[item->neighbors[i]->val]);
            }
        }
        auto ret = dict[1];
        return ret;
    }
};

// @lc code=end
