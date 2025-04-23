#include <iostream>
#include <stack>
#include <string>
using namespace std;

int minLength(string s) {
    stack<char> st;

    for (char c : s) {
        st.push(c);

        if (st.size() >= 2) {
            char top1 = st.top(); // Get the top element
            st.pop();             // Remove the top element
            char top2 = st.top(); // Get the new top element

            // Check for "AB"
            if (top1 == 'B' && top2 == 'A') {
                st.pop(); // Remove 'A'
            }
            // Check for "CD"
            else if (top1 == 'D' && top2 == 'C') {
                st.pop(); // Remove 'C'
            }
            else {
                st.push(top1); // Push back the first popped element if no match
            }
        }
    }

    return st.size();
}

int main() {
    string s1 = "ABFCACDB";
    string s2 = "ACBBD";
    
    cout << "Minimum length of s1: " << minLength(s1) << endl; 
    cout << "Minimum length of s2: " << minLength(s2) << endl; 
    
    return 0;
}
/*class Solution {
 public:
  int minLength(string s) {
    stack<char> stack;

    for (const char c : s)
      if (c == 'B' && match(stack, 'A'))
        stack.pop();
      else if (c == 'D' && match(stack, 'C'))
        stack.pop();
      else
        stack.push(c);

    return stack.size();
  }

 private:
  bool match(const stack<char>& stack, int c) {
    return !stack.empty() && stack.top() == c;
  }
};*/
