#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void print() {
    cout << "-------Linked List-------" << endl;
    Node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

void insertAtFirst(int v) {
    Node *n1 = new Node;
    n1->data = v;
    n1->next = head;
    head = n1;
}

void insertAtLast(int v) {
    Node *n1 = new Node;
    n1->data = v;
    n1->next = NULL;
    if (head == NULL) {
        head = n1;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n1;
}

void insertAt(int x, int index) {
    Node *n1 = new Node;
    n1->data = x;
    n1->next = NULL;

    if (index == 0) { 
        n1->next = head;
        head = n1;
        return;
    }

    Node *ptr = head;
    for (int i = 0; ptr != NULL && i < index - 1; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) { 
        cout << "Index out of range!" << endl;
        delete n1;
        return;
    }

    n1->next = ptr->next;
    ptr->next = n1;
}

void deleteAt(int index) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (index == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *ptr = head;
    for (int i = 0; ptr != NULL && i < index - 1; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        cout << "Index out of range!" << endl;
        return;
    }

    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

int main() {
    insertAtLast(13);
    insertAtLast(7);
    insertAtLast(10);
    print();

    insertAt(5, 1);  
    print();

    insertAt(17, 0); 
    print();

    insertAt(994, 4);
    print();

    deleteAt(2); // Example: Delete element at index 2
    print();

    deleteAt(0); // Example: Delete element at index 0
    print();

    return 0;
}