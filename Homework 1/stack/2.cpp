/*
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> ans{prices};
    stack<int> stack;

    for (int j = 0; j < prices.size(); ++j) {
      // stack[-1] : = i in the problem description.
      while (!stack.empty() && prices[j] <= prices[stack.top()])
        ans[stack.top()] -= prices[j], stack.pop();
      stack.push(j);
    }

    return ans;
  }
};*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> result = prices;
    stack<int> st; // Stack to store indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && prices[st.top()] >= prices[i]) {
            result[st.top()] -= prices[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

// Helper function to print the result
void printVector(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> prices1 = {8, 4, 6, 2, 3};
    vector<int> prices2 = {1, 2, 3, 4, 5};
    vector<int> prices3 = {10, 1, 1, 6};

    printVector(finalPrices(prices1)); // Output: [4, 2, 4, 2, 3]
    printVector(finalPrices(prices2)); // Output: [1, 2, 3, 4, 5]
    printVector(finalPrices(prices3)); // Output: [9, 0, 1, 6]

    return 0;
}
