#include <bits/stdc++.h>
using namespace std;
 class RecentCounter {
public:
queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    // Example 1: ["RecentCounter", "ping", "ping", "ping", "ping"]
    // Input: [[], [1], [100], [3001], [3002]]
    // Expected Output: [null, 1, 2, 3, 3]
    
    RecentCounter recentCounter;
    
    cout << "[null";
    
    // ping(1)
    int result1 = recentCounter.ping(1);
    cout << ", " << result1;
    
    // ping(100)
    int result2 = recentCounter.ping(100);
    cout << ", " << result2;
    
    // ping(3001)
    int result3 = recentCounter.ping(3001);
    cout << ", " << result3;
    
    // ping(3002)
    int result4 = recentCounter.ping(3002);
    cout << ", " << result4;
    
    cout << "]" << endl;

    
    return 0;
}






