#include <bits/stdc++.h>
using namespace std; //home work

const int MAX_NODES = 100;
vector<int> graph[MAX_NODES];
bool visited[MAX_NODES];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int countConnectedComponents(int totalNodes) {
    fill(visited, visited + totalNodes, false);
    int count = 0;
    for (int i = 0; i < totalNodes; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main() {
   /* int totalNodes = 12;

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    addEdge(5, 6);
    addEdge(5, 7);
    addEdge(5, 8);
    addEdge(6, 8);
    addEdge(7, 9);
    addEdge(8, 9);
    addEdge(9, 10);

    int result = countConnectedComponents(totalNodes);
    cout << "Total connected components (states): " << result << endl; */
     int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    cout << countConnectedComponents(n) << endl;
    return 0;

    return 0;
}
/*
12 10
1 2
1 3
2 4
5 6
5 7
5 8
6 8
7 9
8 9
9 10
*/