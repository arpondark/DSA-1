#include <iostream>
using namespace std;

struct SinglyNode {
    int val;
    SinglyNode* next;
    SinglyNode(int x) : val(x), next(nullptr) {}
};

// Reverse singly linked list
SinglyNode* reverseSingly(SinglyNode* head) {
    SinglyNode* prev = nullptr;
    SinglyNode* curr = head;

    while (curr) {
        SinglyNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Print singly linked list
void printSingly(SinglyNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
struct DoublyNode {
    int val;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Reverse doubly linked list
DoublyNode* reverseDoubly(DoublyNode* head) {
    DoublyNode* curr = head;
    DoublyNode* temp = nullptr;

    while (curr) {
        
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev; 
    }

    // Return new head
    return temp ? temp->prev : nullptr;
}

// Print doubly linked list
void printDoubly(DoublyNode* head) {
    while (head) {
        cout << head->val << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {
    
    SinglyNode* sHead = new SinglyNode(1);
    sHead->next = new SinglyNode(2);
    sHead->next->next = new SinglyNode(3);
    sHead->next->next->next = new SinglyNode(4);
    sHead->next->next->next->next = new SinglyNode(5);

    cout << "Original Singly List: ";
    printSingly(sHead);
    sHead = reverseSingly(sHead);
    cout << "Reversed Singly List: ";
    printSingly(sHead);

    
    DoublyNode* dHead = new DoublyNode(10);
    dHead->next = new DoublyNode(20);
    dHead->next->prev = dHead;
    dHead->next->next = new DoublyNode(30);
    dHead->next->next->prev = dHead->next;
    dHead->next->next->next = new DoublyNode(40);
    dHead->next->next->next->prev = dHead->next->next;

    cout << "\nOriginal Doubly List: ";
    printDoubly(dHead);
    dHead = reverseDoubly(dHead);
    cout << "Reversed Doubly List: ";
    printDoubly(dHead);

    return 0;
}
