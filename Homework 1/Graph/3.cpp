#include <bits/stdc++.h>
using namespace std;  //990 leetcode

class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool equationsPossible(vector<string>& equations) {
        p.resize(26);
        for(int i=0;i<26;i++){
            p[i]=i;
        }
        for(auto& a : equations){
            int char1 = a[0]-'a';
             int char2 = a[3]-'a';
             if(a[1]== '='){
                p[find(char1)] = find(char2);
             }
        }
         for (auto& a : equations) {
            int char1 = a[0] - 'a'; 
            int char2 = a[3] - 'a'; 
            if (a[1] == '!' && find(char1) == find(char2)) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<string> equations(n);
    for (int i = 0; i < n; i++) {
        cin >> equations[i];
    }
    
    Solution solution;
    bool result = solution.equationsPossible(equations);
    
    if (result) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
/*
2
b==a
a==b
false

?input:
2
b==a
a==b
output:
true
*/