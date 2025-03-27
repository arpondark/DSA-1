#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;

void print()
{
    cout << "-------Linked List-------" << endl;
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
void insertAtFirst(int v)
{
    Node *n1 = new Node();
    n1->data = v;
    n1->next = head;
    n1->prev = NULL;
    if(head!=NULL)
    {
        head->prev = n1;
    }
    head = n1;
}

void insertAtLast(int x)
{
    Node *n1 = new Node();
    n1->data = x;
    n1->next = NULL;
    if (head == NULL)
    {
        head = n1;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    head = n1;
}

void insertAt(int x, int index)
{
    Node *n1= new Node();
    n1->data = x;
    n1->next = NULL;
    if(index == 0){
        n1->next = head;
        head = n1;
        return;
    }
    index=index-1;
    Node *ptr = head;
    int i=0;
    while(ptr !=NULL && i<index-1){
        ptr = ptr->next;
        i++;
    }
    if(ptr == NULL){
        cout << "Index out of range!" << endl;
        delete n1;
        return;
    }
    n1->next = ptr->next;
    ptr->next = n1;

}
void deleteIndex(int index)
{
    index = index - 1;
    Node *ptr = head;
    int i=0;
    while(ptr != NULL && i < index - 1) {
        ptr = ptr->next;
        i++;
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

int main()
{
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(40);
    insertAtLast(5);
    insertAtLast(60);
    insertAtLast(4);
    insertAt(25, 3);

    print();
    deleteIndex(3);
    print();

    return 0;
}