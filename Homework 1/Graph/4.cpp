#include <bits/stdc++.h>
using namespace std;  //990 leetcode
class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    int firstNodeOfFirstEdge = edges[0][0];
        int secondNodeOfFirstEdge = edges[0][1];
    int firstNodeOfSecondEdge = edges[1][0];
    int secondNodeOfSecondEdge = edges[1][1];
    return (firstNodeOfFirstEdge == firstNodeOfSecondEdge ||
            firstNodeOfFirstEdge == secondNodeOfSecondEdge)
               ? firstNodeOfFirstEdge
               : secondNodeOfFirstEdge;
  }
};
int main() {
  int n;
  cin >> n;

  vector<vector<int>> edges(n - 1, vector<int>(2));
  for (int i = 0; i < n - 1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }

  Solution solution;
  int result = solution.findCenter(edges);

  cout << result << endl;

  return 0;
}
/*
? i am using cph extention to test 
4    
1 2
2 3 
4 2
output:2
!author: md shazan mahmud arpon id :0112410351
*/