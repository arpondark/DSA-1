#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    for (char ch : s) {
        if (!st.empty() && st.top() == ch) {
            st.pop(); // Remove the duplicate
        } else {
            st.push(ch); // Add character to stack
        }
    }

    // Build result from stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end()); 
    return result;
}

int main() {
    cout << removeDuplicates("abbaca") << endl; // Output: "ca"
    cout << removeDuplicates("azxxzy") << endl; // Output: "ay"
    return 0;
}
