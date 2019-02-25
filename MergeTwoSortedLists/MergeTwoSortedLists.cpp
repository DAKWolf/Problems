/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
            
        if (l1->val > l2->val)
            std::swap(l1, l2);
        
        ListNode* result = l1;
        ListNode* pl1 = l1;
        while (l1 != nullptr && l2 != nullptr) {
            const int vl1 = l1->val;
            const int vl2 = l2->val;

            if (vl1 > vl2) {
                pl1->next = l2;
                std::swap(l1, l2);
            }
            if (l1->next == nullptr) {
                std::swap(l1->next, l2);
            }

            pl1 = l1;                
            l1 = l1->next;
        }
        
        return result;
    }
};
