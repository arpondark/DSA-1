#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
    1. creating
    2. isFull()-> NA
    3. isEmpty()-> empty()
    4. push()-> push_back()
    5. pop()-> pop_back()
    6. peek()-> back()
    7. traversing
    */
    vector<int> stck;
    cout<<stck.size()<<endl;
    cout<<stck.empty()<<endl;
    stck.push_back(7);
    stck.push_back(5);
    stck.push_back(9);
    stck.push_back(10);
    cout<<stck.back()<<endl;
    stck.pop_back();
    cout<<stck.back()<<endl;
    for(int i=0;i<stck.size();i++){
        cout<<stck[i]<<" ";
    }
    cout<<endl;

    for(int i:stck){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
