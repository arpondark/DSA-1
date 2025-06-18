#include<bits/stdc++.h>
using namespace std;

int G[10][10];


int main(){
    int V;
    cin>>V;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>G[i][j];
        }
    }
    cout<<"--------Graph--------"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(G[i][j] != G[j][i]){
                cout<<"Directed Graph"<<endl;
                return -1;
            }
        }
    }
    cout<<"Undirected Graph"<<endl;
    return 0;
}
/*
1 0 1 1 0
0 0 0 1 0
1 0 0 0 0
1 1 0 0 1
0 0 0 0 0
*/
