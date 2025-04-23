#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node *top = NULL;
bool isEmpty(){
    return top==NULL;
}

void push(int x){
    Node *newNode = new Node;
    newNode->val = x;
    newNode->next = NULL;

    newNode->next = top;
    top = newNode;
}
int pop(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    Node *tmp = top;
    top = top->next;
    int item = tmp->val;
    delete tmp;
    return item;
}
int peek(){
    return top->val;
}
void print(){
    cout<<"----------Stack--------"<<endl;
    Node *ptr = top;
    while(ptr!=NULL){
        cout<<ptr->val<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main(){

    push(7);
    push(5);
    push(10);
    push(13);
    print();
    cout<<pop()<<endl;
    print();
    return 0;
}
