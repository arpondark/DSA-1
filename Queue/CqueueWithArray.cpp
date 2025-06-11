#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

int Q[SIZE],F=-1,R=-1;
bool isFull(){
    return (R+1)%SIZE==F;
}
bool isEmpty(){
    return F==-1;
}
void enqueue(int item){
    if(isFull()==true){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    if(F==-1)
        F = R = 0;
    else
        R = (R+1)%SIZE;
    Q[R] = item;
}
int dequeue(){
    if(isEmpty()==true){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = Q[F];
    if(F==R)
    {
        F=R=-1;
    }
    else
        F = (F+1)%SIZE;
    return item;
}

// Homework
// Queue print
void print(){

}
int main(){
    //cout<<dequeue()<<endl;
    enqueue(13);
    enqueue(7);
    enqueue(17);
    cout<<Q[F]<<" "<<Q[R]<<endl;
    //cout<<dequeue()<<endl;
    //cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<dequeue()<<endl;
    cout<<Q[F]<<" "<<Q[R]<<endl;
    enqueue(10);
    enqueue(5);
    enqueue(11);
    cout<<Q[F]<<" "<<Q[R]<<endl;
    return 0;
}

