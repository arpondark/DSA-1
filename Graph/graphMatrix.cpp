#include<bits/stdc++.h>
using namespace std;

int G[10][10];
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
..

*/

int main(){
    int V,E,a,b,c;
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        cin>>a>>b>>c;
        G[a][b] = c;
        //G[b][a] = c;
    }
    cout<<"--------Graph--------"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
5 7
0 1 10
0 3 13
0 4 7
1 2 15
1 3 20
2 4 9
3 4 11
*/
