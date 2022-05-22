/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
#include <iostream>
///* Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* loop = head;
    ListNode *less_head = NULL, *less_tail = NULL, *other_tail = NULL,
             *other_head = NULL;
    while (loop != NULL) {
      if (loop->val < x) {
        if (less_head == NULL) {
          less_head = loop;
          less_tail = loop;
        } else {
          less_tail->next = loop;
          less_tail = less_tail->next;
        }
        loop = loop->next;
        less_tail->next = NULL;
      } else {
        if (other_head == NULL) {
          other_head = loop;
          other_tail = other_head;
        } else {
          other_tail->next = loop;
          other_tail = other_tail->next;
        }
        loop = loop->next;
        other_tail->next = NULL;
      }
    }
    if (less_tail == NULL) {
      less_head = other_head;
    } else {
      less_tail->next = other_head;
    }
    return less_head;
  }
};
int main() {
  ListNode* head = new ListNode(2);
  head->next = new ListNode(1);
  ListNode* loop = head;
  while (loop != NULL) {
    std::cout << loop->val << " ";
    loop = loop->next;
  }
  std::cout << std::endl;
  Solution s;
  loop = s.partition(head, 2);
  while (loop != NULL) {
    std::cout << loop->val << " ";
    loop = loop->next;
  }
  std::cout << std::endl;
}
// @lc code=end
