#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    
    ListNode* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    tail->next = head;  

   
    k = k % length;
    int stepsToNewTail = length - k;
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}


ListNode* buildList(const initializer_list<int>& vals) {
    ListNode *head = nullptr, *tail = nullptr;
    for (int v : vals) {
        ListNode* node = new ListNode(v);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }
    return head;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head1 = buildList({1, 2, 3, 4, 5});
    head1 = rotateRight(head1, 2);
    printList(head1);  // Output: 4 5 1 2 3

    ListNode* head2 = buildList({0, 1, 2});
    head2 = rotateRight(head2, 4);
    printList(head2);  // Output: 2 0 1

    return 0;
}
/*
#include <iostream>
using namespace std;

struct DoublyListNode {
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

DoublyListNode* rotateRight(DoublyListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Count length and get tail
    int length = 1;
    DoublyListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    k = k % length;
    if (k == 0) return head;

    // Find new head: move (length - k) steps from head
    int steps = length - k;
    DoublyListNode* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    DoublyListNode* newHead = newTail->next;

    // Break and reconnect
    newTail->next = nullptr;
    newHead->prev = nullptr;

    tail->next = head;
    head->prev = tail;

    return newHead;
}

// Helper to create a doubly linked list
DoublyListNode* buildDoublyList(const initializer_list<int>& vals) {
    DoublyListNode *head = nullptr, *tail = nullptr;
    for (int val : vals) {
        DoublyListNode* node = new DoublyListNode(val);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

// Print doubly linked list forward
void printDoublyList(DoublyListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DoublyListNode* head1 = buildDoublyList({1, 2, 3, 4, 5});
    head1 = rotateRight(head1, 2);
    printDoublyList(head1); // Output: 4 5 1 2 3

    DoublyListNode* head2 = buildDoublyList({0, 1, 2});
    head2 = rotateRight(head2, 4);
    printDoublyList(head2); // Output: 2 0 1

    return 0;
}

*/

