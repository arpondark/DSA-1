#include <bits/stdc++.h>
using namespace std;  //997 leetcode
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>count(n+1);
        for(auto& t:trust){
            count[t[0]]--; // t[0] trusts someone, so decrease their count
            count[t[1]]++; 
        }
        for(int i=0;i<n;i++){
            if(count[i]==n-1) return i; 
        }
        return -1; 
    }
};
int main() {
    int n, m;
    cin >> n >> m;  

    vector<vector<int>> trust;
    for (int i = 0; i < m; i++) {
        vector<int> edge(2);
        cin >> edge[0] >> edge[1];
        trust.push_back(edge);
    }

    Solution solution;
    int result = solution.findJudge(n, trust);

    cout << result << endl;

    return 0;
}
/*
?input:
3 2
1 3
2 3
!output: 3
*/