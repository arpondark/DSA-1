#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = buildList({2, 4, 3});  // 342
    ListNode* l2 = buildList({5, 6, 4});  // 465

    ListNode* result = addTwoNumbers(l1, l2); // 807 => [7, 0, 8]

    cout << "Result: ";
    printList(result);

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

DoublyListNode* addTwoNumbers(DoublyListNode* l1, DoublyListNode* l2) {
    DoublyListNode* dummy = new DoublyListNode(0);
    DoublyListNode* curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        DoublyListNode* newNode = new DoublyListNode(sum % 10);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    return dummy->next;
}

// Helper to build a doubly linked list from values
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

// Helper to print the list forward
void printList(DoublyListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DoublyListNode* l1 = buildDoublyList({2, 4, 3});  // 342
    DoublyListNode* l2 = buildDoublyList({5, 6, 4});  // 465

    DoublyListNode* result = addTwoNumbers(l1, l2); // 807 => [7, 0, 8]

    cout << "Result: ";
    printList(result);

    return 0;
}

*/