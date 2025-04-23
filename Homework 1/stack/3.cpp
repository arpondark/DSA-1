/*
class Solution {
 public:
  string reversePrefix(string word, char ch) {
    reverse(word.begin(), word.begin() + word.find(ch) + 1);
    return word;
  }
};*/
/*Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reversePrefix(string word, char ch) {
    int idx = word.find(ch); // find first occurrence of ch
    if (idx != string::npos) {
        reverse(word.begin(), word.begin() + idx + 1);
    }
    return word;
}

int main() {
    cout << reversePrefix("abcdefd", 'd') << endl; // Output: dcbaefd
    cout << reversePrefix("xyxzxe", 'z') << endl;  // Output: zxyxxe
    cout << reversePrefix("abcd", 'z') << endl;    // Output: abcd
    return 0;
}
