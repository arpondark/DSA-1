#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (auto& edge : edges)
            unionSet(find(edge[0]), find(edge[1]));

        return find(source) == find(destination);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            parent[rootX] = rootY;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }
    int source, destination;
    cin >> source >> destination;

    Solution sol;
    bool result = sol.validPath(n, edges, source, destination);
    cout << (result ? "true" : "false") << endl;

    return 0;
}

/*
Test case 1:
Input:
3 3
0 1
1 2
2 0
0 2
Output:
true

Test case 2:
Input:
6 5
0 1
0 2
3 5
5 4
4 3
0 5
Output:
false
*/
