#include <iostream>
#include <stack>
using namespace std;

string removeDigits(string s) {
    stack<char> st;

    for (char c : s) {
        if (isdigit(c)) {
            if (!st.empty() && !isdigit(st.top())) {
                st.pop();  
            }
        } else {
            st.push(c);  
        }
    }

   
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    string s1 = "abc";
    string s2 = "cb34";

    cout << "Output 1: " << removeDigits(s1) << endl;  // Output: "abc"
    cout << "Output 2: " << removeDigits(s2) << endl;  // Output: ""

    return 0;
}
