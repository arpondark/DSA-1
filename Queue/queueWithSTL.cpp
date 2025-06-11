#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;
    cout<<Q.empty()<<endl;
    Q.push(13);
    Q.push(7);
    Q.push(5);
    Q.push(10);
    cout<<Q.size()<<endl;
    Q.pop();
    cout<<Q.front()<<" "<<Q.back()<<endl;
}
