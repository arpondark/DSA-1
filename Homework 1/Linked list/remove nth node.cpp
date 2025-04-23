#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Remove the nth node from the end of the list
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);  // Create a dummy node to handle edge cases
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    // Move both fast and slow pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;  // Return the head of the modified list
}

// Helper to build the linked list
ListNode* buildList(initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Helper to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = buildList({1, 2, 3, 4, 5});
    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, 2);
    cout << "After Removing 2nd Node from End: ";
    printList(head);

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


DoublyListNode* removeNthFromEnd(DoublyListNode* head, int n) {
    if (!head) return nullptr;

    
    DoublyListNode* dummy = new DoublyListNode(0);
    dummy->next = head;
    head->prev = dummy;
    DoublyListNode* fast = dummy;
    DoublyListNode* slow = dummy;

   
    for (int i = 0; i <= n; ++i) {
        if (fast) fast = fast->next;
    }

    
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    
    DoublyListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    if (slow->next) {
        slow->next->prev = slow;
    }

    delete nodeToDelete;

    
    DoublyListNode* newHead = dummy->next;
    delete dummy;  // Clean up the dummy node
    return newHead;
}


DoublyListNode* buildDoublyList(initializer_list<int> values) {
    DoublyListNode* head = nullptr;
    DoublyListNode* tail = nullptr;
    for (int val : values) {
        DoublyListNode* node = new DoublyListNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}


void printList(DoublyListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DoublyListNode* head = buildDoublyList({1, 2, 3, 4, 5});
    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, 2);
    cout << "After Removing 2nd Node from End: ";
    printList(head);

    return 0;
}

*/