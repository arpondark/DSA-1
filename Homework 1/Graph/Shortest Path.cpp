#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
int dist[N];

void bfs(int start, int n) {
    for (int i = 0; i < n; i++) dist[i] = -1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5;
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(2);
    g[1].push_back(3);
    g[2].push_back(3);
    g[3].push_back(4);

    bfs(0, n);
    for (int i = 0; i < n; i++)
        cout << "Distance from 0 to " << i << " is " << dist[i] << endl;

    return 0;
}


/*

?Graph:
5 nodes (0 to 4)
Edges:
0 → 1  
0 → 2  
1 → 2  
1 → 3  
2 → 3  
3 → 4

*/