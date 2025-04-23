#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minOperations(vector<string>& logs) {
    int depth = 0;

    for (const string& log : logs) {
        if (log == "../") {
            if (depth > 0) depth--; 
        } else if (log != "./") {
            depth++; 
        }
        
    }

    return depth;
}

int main() {
    vector<string> logs1 = {"d1/","d2/","../","d21/","./"};
    cout << minOperations(logs1) << endl;  // Output: 2

    vector<string> logs2 = {"d1/","d2/","./","d3/","../","d31/"};
    cout << minOperations(logs2) << endl;  // Output: 3

    vector<string> logs3 = {"d1/","../","../","../"};
    cout << minOperations(logs3) << endl;  // Output: 0

    return 0;
}
