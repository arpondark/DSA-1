#include <vector>
#include <functional>
#include <cstring>
#include <iostream>

using namespace std; // !leetcode 547. Number of Provinces

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        int provinceCount = 0;
        bool visited[cities];
        memset(visited, false, sizeof(visited));
      
        function<void(int)> dfs = [&](int cityIndex) {
            visited[cityIndex] = true;
            for (int j = 0; j < cities; ++j) {
                if (!visited[j] && isConnected[cityIndex][j]) {
                    dfs(j);
                }
            }
        };
      
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                dfs(i);
                ++provinceCount;
            }
        }
      
        return provinceCount;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> isConnected(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }
    
    Solution solution;
    int result = solution.findCircleNum(isConnected);
    cout << result << endl;
    
    return 0;
}
 /*
 !test case
 ? Input:
3
1 1 0
1 1 0
0 0 1

Expected Output:
2
 */