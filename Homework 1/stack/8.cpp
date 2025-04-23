#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxDepth(string s) {
    int max_depth = 0, current_depth = 0;

    for (char c : s) {
        if (c == '(') {
           
            current_depth++;
            max_depth = max(max_depth, current_depth); 
        } else if (c == ')') {
      
            current_depth--;
        }
    }

    return max_depth;
}

int main() {
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s1) << endl;  // Output: 3

    string s2 = "(1)+((2))+(((3)))";
    cout << maxDepth(s2) << endl;  // Output: 3

    string s3 = "()(())((()()))";
    cout << maxDepth(s3) << endl;  // Output: 3

    return 0;
}
