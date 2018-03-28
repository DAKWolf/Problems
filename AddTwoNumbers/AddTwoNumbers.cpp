/*
2. Add Two Numbers

You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input : (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output : 7 -> 0 -> 8
  Explanation : 342 + 465 = 807.
*/

#include <iostream>

// Definition for singly - linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 && !l2)
      return l1;

    if (l2 && !l1)
      return l2;

    ListNode* res = new ListNode(0);
    auto pres = res;
    auto p1 = l1;
    auto p2 = l2;

    if (l1 && l2)
    {
      int dig = 0;
      while (p1 || p2)
      {
        if (p1)
        {
          if (p2)
          {
            const auto val = (p1->val + p2->val + dig) % 10;
            dig = (p1->val + p2->val + dig) / 10;
            pres->val = val;
            p1 = p1->next;
            p2 = p2->next;
            if (p1 || p2 || dig)
            {
              pres->next = new ListNode(0);
              pres = pres->next;
            }
          }
          else
          {
            const auto val = (p1->val + dig) % 10;
            dig = (p1->val + dig) / 10;
            pres->val = val;
            p1 = p1->next;
            if (p1 || dig)
            {
              pres->next = new ListNode(0);
              pres = pres->next;
            }
          }
        }
        else if (p2)
        {
          const auto val = (p2->val + dig) % 10;
          dig = (p2->val + dig) / 10;
          pres->val = val;
          p2 = p2->next;
          if (p2 || dig)
          {
            pres->next = new ListNode(0);
            pres = pres->next;
          }
        }
      }

      if (dig > 0)
        pres->val = dig;
    }

    return res;
  }
  bool checkExample()
  {
    ListNode listNode11(2);
    ListNode listNode12(4);
    ListNode listNode13(3);
    listNode11.next = &listNode12;
    listNode12.next = &listNode13;

    ListNode listNode21(5);
    ListNode listNode22(6);
    ListNode listNode23(4);
    listNode21.next = &listNode22;
    listNode22.next = &listNode23;

    ListNode listNodeCheck1(7);
    ListNode listNodeCheck2(0);
    ListNode listNodeCheck3(8);
    listNodeCheck1.next = &listNodeCheck2;
    listNodeCheck2.next = &listNodeCheck3;

    ListNode* result = addTwoNumbers(&listNode11, &listNode21);
    ListNode* check = &listNodeCheck1;
    bool is_ok(true);
    int counter(0);
    while (result->next && check->next)
    {
      is_ok &= result->val == check->val;
      counter++;
    }
    is_ok &= counter == 3;

    return is_ok;
  }
};


int main()
{
  Solution solution;
  solution.checkExample();

  return 0;
}
