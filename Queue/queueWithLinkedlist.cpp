#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node *F=NULL;
Node *R = NULL;
bool isEmpty(){
    return F==NULL;
}
void enqueue(int item){
    Node *newNode = new Node;
    newNode->val = item;
    newNode->next = NULL;
    if(F==NULL){
        F= newNode;
        R = newNode;
    }
    else{
        R->next = newNode;
        R = newNode;
    }
}
int dequeue(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    Node *tmp = F;
    int item = tmp->val;
    if(F==R){
        F = R = NULL;
    }
    else{
        F = F->next;
    }
    delete tmp;
    return item;
}
void print(){
    Node *tmp = F;
    while(tmp!=NULL){
        cout<<tmp->val<<"->";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main(){
    enqueue(13);
    enqueue(5);
    cout<<dequeue()<<endl;
    enqueue(7);
    enqueue(17);
    enqueue(10);
    print();
    return 0;
}
