#include<bits/stdc++.h>
using namespace std;
#define SIZE 10

int arr[SIZE],top=-1;

bool isFull(){
    return top==SIZE-1;
}

bool isEmpty(){
    return top==-1;
}
void push(int x){
    if(isFull()){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    top = top + 1;
    arr[top] = x;
    cout<<"Successful"<<endl;
}
int pop(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = arr[top];
    top = top-1;
    return item;
}
int peek(){
    return arr[top];
}
void print(){
    cout<<"----------Stack--------"<<endl;
    for(int i=0;i<=top;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    push(7);
    push(5);
    push(9);
    push(13);
    push(17);
    print();
    cout<<pop()<<endl;
    print();

    return 0;
}
