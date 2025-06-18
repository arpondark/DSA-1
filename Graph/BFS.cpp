#include<bits/stdc++.h>
using namespace std;
#define INF 10000
struct Node{
    int v,w;
    Node *next;
};
Node *head[10];
int V,E;
void makeGraph(int s,int d,int w){
    Node *new_node = new Node;
    new_node->v = d;
    new_node->w = w;
    new_node->next = NULL;
    if(head[s]==NULL){
        head[s] = new_node;
    }
    else{
        new_node->next = head[s];
        head[s] = new_node;
    }

}
void printList(Node *ptr){
    while(ptr){
        cout<<"("<<ptr->v<<","<<ptr->w<<")->";
        ptr = ptr->next;
    }
    cout<<endl;
}
void BFS(int s){
    int color[10],p[10],dst[10];
    for(int i=0;i<V;i++){
        color[i] = 'W';
        p[i] = -1;
        dst[i] = INF;
    }
    color[s] = 'G';
    dst[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        Node *vertices = head[cur];
        while(vertices){
            int neighbor = vertices->v;
            if(color[neighbor]=='W'){
                color[neighbor] = 'G';
                p[neighbor] = cur;
                dst[neighbor] = dst[cur] + 1;
                Q.push(neighbor);
            }
            vertices = vertices->next;
        }
        color[cur] = 'B';
        cout<<cur<<"->";
    }
}
int main(){
    cin>>V>>E;
    int a,b,c;
    for(int i=1;i<=E;i++){
        cin>>a>>b>>c;
        makeGraph(a,b,c);
        makeGraph(b,a,c);
    }
    cout<<"----------Graph--------"<<endl;
    for(int i=0;i<V;i++){
        cout<<" Adjacent of "<<i<<": ";
        printList(head[i]);
    }
    BFS(0);
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
