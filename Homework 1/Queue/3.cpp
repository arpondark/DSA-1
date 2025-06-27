/*  //!LeetCode Problem: 2073. Time Needed to Buy Tickets 
class Solution {
 public:
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int ans = 0;

    for (int i = 0; i < tickets.size(); ++i)
      if (i <= k)
        ans += min(tickets[i], tickets[k]);
      else
        ans += min(tickets[i], tickets[k] - 1);

    return ans;
  }
};
*/
#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;
    for (int i = 0; i < tickets.size(); ++i) {
        if (i <= k)
            time += min(tickets[i], tickets[k]);
        else
            time += min(tickets[i], tickets[k] - 1);
    }
    return time;
}

int main() {
    // Example 1
    vector<int> tickets1 = {2, 3, 2};
    int k1 = 2;
    cout << "Time for person " << k1 << " to buy tickets: " << timeRequiredToBuy(tickets1, k1) << endl;

    // Example 2
    vector<int> tickets2 = {5, 1, 1, 1};
    int k2 = 0;
    cout << "Time for person " << k2 << " to buy tickets: " << timeRequiredToBuy(tickets2, k2) << endl;

    return 0;
}
/*
Let tickets = [2,3,2], k = 2 (the last person).
- For i=0 (<=k): min(2, tickets[2]=2) -> 2
- For i=1 (<=k): min(3, 2) -> 2
- For i=2 (<=k): min(2,2) -> 2
Total = 2+2+2 = 6.
*/