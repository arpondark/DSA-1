#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};


Node* buildList(initializer_list<int> values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int val : values) {
        Node* node = new Node(val);
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

Node* reverseList(Node* head) {
    Node* temp = nullptr;
    Node* current = head;

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


void printOdd(Node* head) {
    cout << "Odd numbers in reversed list: ";
    while (head) {
        if (head->val % 2 != 0)
            cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = buildList({10, 7, 8, 3, 6, 5, 2}); 

    head = reverseList(head);  

    printOdd(head);  

    return 0;
}
