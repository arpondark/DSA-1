#include <iostream>
#include <string>
using namespace std;

string makeGood(string s) {
    string result;

    for (char ch : s) {
        if (!result.empty() && abs(result.back() - ch) == 32) {
            result.pop_back(); 
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {
    cout << makeGood("leEeetcode") << endl; // Output: "leetcode"
    cout << makeGood("abBAcC") << endl;     // Output: ""
    cout << makeGood("s") << endl;          // Output: "s"
    return 0;
}
