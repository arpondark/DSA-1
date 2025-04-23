#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to convert binary linked list to decimal
int getDecimalValue(ListNode* head) {
    int result = 0;
    while (head) {
        result = (result << 1) | head->val;
        head = head->next;
    }
    return result;
}

// Helper to build a linked list from an array
ListNode* buildList(initializer_list<int> values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* node = new ListNode(val);
        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main() {
    ListNode* head = buildList({1, 0, 1});
    cout << "Decimal value: " << getDecimalValue(head) << endl;
    return 0;
}

/*
#include <iostream>
using namespace std;

struct DoublyNode {
    int val;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Function to convert binary doubly linked list to decimal
int getDecimalValue(DoublyNode* head) {
    int result = 0;
    while (head) {
        result = (result << 1) | head->val;
        head = head->next;
    }
    return result;
}

// Helper to build doubly linked list from initializer_list
DoublyNode* buildDoublyList(initializer_list<int> values) {
    DoublyNode* head = nullptr;
    DoublyNode* tail = nullptr;
    for (int val : values) {
        DoublyNode* node = new DoublyNode(val);
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

// Print the doubly linked list
void printDoublyList(DoublyNode* head) {
    while (head) {
        cout << head->val << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    DoublyNode* head = buildDoublyList({1, 0, 1});
    cout << "Doubly Linked List: ";
    printDoublyList(head);

    int result = getDecimalValue(head);
    cout << "Decimal value: " << result << endl;

    return 0;
}

*/

