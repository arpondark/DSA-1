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
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* x = head;
            while(x !=NULL)
            {
                while(x->next && x->val == x->next->val)
                {
                    x->next = x->next->next;
                }
                    x= x->next;
            }
            return head;
        }
    };