#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> g[N];
bool visited[N], inStack[N];
bool hasCycle = false;

void dfs(int u) {
    visited[u] = inStack[u] = true;
    for (int v : g[u]) {
        if (!visited[v])
            dfs(v);
        else if (inStack[v])
            hasCycle = true;
    }
    inStack[u] = false;
}

int main() {
    int n = 5;
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(2);
    g[1].push_back(3);
    g[2].push_back(3);
    g[3].push_back(4);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i);
    }

    cout << (hasCycle ? "Cycle Found" : "No Cycle") << endl;
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