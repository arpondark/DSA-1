#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}


ListNode* removeNodes(ListNode* head) {
    head = reverseList(head);

    ListNode* curr = head;
    int maxVal = head->val;

    while (curr && curr->next) {
        if (curr->next->val < maxVal) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    return reverseList(head);
}


ListNode* buildList(initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* node = new ListNode(val);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }
    return head;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = buildList({5, 2, 13, 3, 8});
    cout << "Original: ";
    printList(head);

    head = removeNodes(head);
    cout << "Modified: ";
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

// Reverse a doubly linked list
DoublyListNode* reverseList(DoublyListNode* head) {
    DoublyListNode* temp = nullptr;
    DoublyListNode* current = head;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp)
        head = temp->prev;

    return head;
}

// Remove nodes that have a greater value on the right side
DoublyListNode* removeNodes(DoublyListNode* head) {
    head = reverseList(head);

    DoublyListNode* curr = head;
    int maxVal = curr->val;

    while (curr && curr->next) {
        if (curr->next->val < maxVal) {
            DoublyListNode* temp = curr->next;
            curr->next = temp->next;
            if (temp->next) {
                temp->next->prev = curr;
            }
            delete temp;
        } else {
            curr = curr->next;
            maxVal = curr->val;
        }
    }

    return reverseList(head);
}

// Helper to build doubly linked list
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

// Helper to print the doubly linked list
void printList(DoublyListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DoublyListNode* head = buildDoublyList({5, 2, 13, 3, 8});
    cout << "Original: ";
    printList(head);

    head = removeNodes(head);
    cout << "Modified: ";
    printList(head);

    return 0;
}

*/
