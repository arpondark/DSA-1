#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *head = NULL;
// Function to print the linked list
void print(Node* h) {
    cout << "-------Linked List-------" << endl;
    Node *ptr = h;
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

// Merge function for two sorted lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    tail->next = head1 ? head1 : head2;
    return dummy.next;
}

// Function to remove duplicates from a sorted linked list
Node* removeDuplicates(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Helper to create a new sorted list from initializer list
Node* createSortedList(initializer_list<int> values) {
    Node* newHead = NULL;
    Node* tail = NULL;
    for (int val : values) {
        Node* n = new Node{val, NULL};
        if (!newHead) {
            newHead = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return newHead;
}

int main() {
    Node* list1 = createSortedList({1, 2, 4});
    Node* list2 = createSortedList({1, 3, 4});

    cout << "List 1:\n";
    print(list1);
    cout << "List 2:\n";
    print(list2);

    Node* merged = mergeSortedLists(list1, list2);
    cout << "Merged List:\n";
    print(merged);

    Node* deduped = removeDuplicates(merged);
    cout << "Deduplicated List:\n";
    print(deduped);

    return 0;
}
