#include<bits/stdc++.h>
using namespace std;

// Maximum number of nodes in the graph (0 to 99)
const int N = 100; 

// Global array to track which nodes have been visited during BFS
bool visited[N];    

// Adjacency list representation of the graph
// adj[i] contains all neighbors of node i
vector<int> adj[N];

int main(){
    // Initialize all nodes as unvisited (false/0)
    // This is necessary because global arrays may contain garbage values
    for(int i = 0; i < N; i++){
        visited[i] = 0;
    }
    
    // Read number of nodes (n) and edges (m)
    int n,m;
    cin >>n>>m;
    
    // Variables to store endpoints of each edge
    int x,y;
    
    // Read all edges and build the adjacency list
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        // Add edge x-y (undirected graph, so add both directions)
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // BFS Implementation
    // Queue to store nodes to be processed
    queue<int> q;
    
    // Start BFS from node 1
    q.push(1);
    visited[1] = true;  // Mark starting node as visited
    
    // Continue BFS until queue is empty
    while(!q.empty()){
       // Get the front node from queue
       int node = q.front();
       q.pop();
       
       // Process current node (print it)
       cout<< node << endl;
       
       // Iterator to traverse all neighbors of current node
       vector<int> :: iterator it;
       
       // Visit all unvisited neighbors
       for(it = adj[node].begin(); it != adj[node].end(); it++){
           // If neighbor hasn't been visited yet
           if(!visited[*it]){
               visited[*it] = 1;  // Mark as visited
               q.push(*it);       // Add to queue for future processing
           }
       }
    }
    return 0;
}

