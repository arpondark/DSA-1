#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> scores;  

    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int total = a + b + c + d;
        scores.push_back({total, i});
    }

    // Sort by descending total score, then by ascending ID
    sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) return a.first > b.first; 
        return a.second < b.second; 
    });

    // Find Thomas's rank (ID = 1)
    for (int rank = 0; rank < n; rank++) {
        if (scores[rank].second == 1) {
            cout << rank + 1 << endl;
            break;
        }
    }

    return 0;
}
