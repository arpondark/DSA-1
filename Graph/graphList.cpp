#include<bits/stdc++.h>
using namespace std;

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
