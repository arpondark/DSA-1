#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
void insertAtFirst(int v){
    Node *n1 = new Node;
    n1->data = v;
    n1->next = NULL;
    n1->prev = NULL;
    if(head==NULL){
        head = n1;
    }
    else{
        n1->next = head;
        head->prev = n1;
        head = n1;
    }


}
void print(){
    cout<<"-------Linked List-------"<<endl;
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<endl;

}
int main(){
    insertAtFirst(7);
    insertAtFirst(5);
    insertAtFirst(13);
    insertAtFirst(10);
    insertAtFirst(2);

    print();
}
