#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insertAtFirst(int c)
{
    Node *n1 = new Node();
    n1->data = c;
    n1->next = head;
    n1->prev = NULL;

    if (head != NULL) {
        head->prev = n1;
    }

    head = n1; 
}

void insertAt(int index, int value)
{
    if (index == 0) {
        insertAtFirst(value);
        return;
    }

    Node *n1 = new Node();
    n1->data = value;
    Node *temp = head;
    
    int count = 0;
    while (temp != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        n1->next = temp->next;
        n1->prev = temp;
        
        if (temp->next != NULL) {
            temp->next->prev = n1;
        }
        
        temp->next = n1;
    }
    else {
        cout << "Index out of bounds!" << endl;
    }
}

void deleteAt(int index)
{
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node *temp = head;
    
    int count = 0;
    while (temp != NULL && count < index) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        cout << "Deleted value: " << temp->data << endl;
        delete temp;
    }
    else {
        cout << "Index out of bounds!" << endl;
    }
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);

    print();  

    insertAt(1, 25); 
    print();  

    deleteAt(2); 
    print();  

    deleteAt(0); 
    print();  

    return 0;
}
