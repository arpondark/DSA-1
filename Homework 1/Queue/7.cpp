/* //!2944. Minimum Number of Coins for Fruits
class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    const int n = prices.size();
    int ans = 0;
    using P = pair<int, int>;
    // Stores (dp[i], i), where dp[i] := the minimum number of coins to acquire
    // fruits[i:] (0-indexed).
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(0, n);

    for (int i = n - 1; i >= 0; --i) {
      while (!minHeap.empty() && minHeap.top().second > (i + 1) * 2)
        minHeap.pop();
      ans = prices[i] + minHeap.top().first;
      minHeap.emplace(ans, i);
    }

    return ans;
  }
};
*/

#include <bits/stdc++.h>

using namespace std;

int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n + 1, 0); // dp[i] = min coins needed from i to end

    // Min heap to maintain minimum dp[j] in range i+1 to i+i+1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // Start from the back
    for (int i = n - 1; i >= 0; --i) {
        // Remove entries out of range [i+1, (i+1)*2]
        // (i+1)*2 is equivalent to 2*i + 2 using 0-indexed i
        while (!pq.empty() && pq.top().second > (i + 1) * 2)
            pq.pop();

        int min_future_cost = pq.empty() ? 0 : pq.top().first;
        dp[i] = prices[i] + min_future_cost;
        pq.emplace(dp[i], i);  // (cost, index)
    }

    return dp[0];
}


int main() {
    vector<int> prices1 = {3,1,2};
    vector<int> prices2 = {1,10,1,1};
    vector<int> prices3 = {26,18,6,12,49,7,45,45};

    cout << minimumCoins(prices1) << endl; // Output: 4
    cout << minimumCoins(prices2) << endl; // Output: 2
    cout << minimumCoins(prices3) << endl; // Output: 39

    return 0;
}
