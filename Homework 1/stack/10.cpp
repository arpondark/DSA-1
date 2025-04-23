#include <iostream>
#include <stack>
using namespace std;

// Function to simulate the backspace typing
string processString(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) {
                st.pop();  // Simulate backspace
            }
        } else {
            st.push(c);  // Add character to stack
        }
    }
    
    // Rebuild the string from the stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
}

// Function to check if the two strings are equal after backspacing
bool backspaceCompare(string s, string t) {
    return processString(s) == processString(t);
}

int main() {
    string s1 = "ab#c", t1 = "ad#c";
    string s2 = "ab##", t2 = "c#d#";
    string s3 = "a#c", t3 = "b";
    
    cout << backspaceCompare(s1, t1) << endl;  // Expected: true
    cout << backspaceCompare(s2, t2) << endl;  // Expected: true
    cout << backspaceCompare(s3, t3) << endl;  // Expected: false
    
    return 0;
}
