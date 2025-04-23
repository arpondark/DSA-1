/*class Solution {
    public:
        
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            ListNode *pointerA = headA;  
            ListNode *pointerB = headB;  
    
    
            while (pointerA != pointerB) {
                
                pointerA = pointerA ? pointerA->next : headB;
                pointerB = pointerB ? pointerB->next : headA;
            }
    
           
            return pointerA;
        }
    };
    */
   #include <bits/stdc++.h>
   using namespace std;
   
   struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
   };
   
   
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if (!headA || !headB) return NULL;
   
       ListNode *ptrA = headA;
       ListNode *ptrB = headB;
   
       while (ptrA != ptrB) {
           ptrA = ptrA ? ptrA->next : headB;
           ptrB = ptrB ? ptrB->next : headA;
       }
   
       return ptrA; 
   }
   int main() {
    
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);
    c1->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* a1 = new ListNode(4);
    a1->next = new ListNode(1);
    a1->next->next = c1;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* b1 = new ListNode(5);
    b1->next = new ListNode(6);
    b1->next->next = new ListNode(1);
    b1->next->next->next = c1;

    ListNode* intersection = getIntersectionNode(a1, b1);
    if (intersection)
        cout << "Intersected at '" << intersection->val << "'" << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}

   
    