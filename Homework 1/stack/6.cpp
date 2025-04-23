#include <iostream>
#include <vector>
#include <string>
using namespace std;

int calPoints(vector<string>& operations) {
    vector<int> record;

    for (const string& op : operations) {
        if (op == "C") {
            if (!record.empty()) record.pop_back();
        } else if (op == "D") {
            if (!record.empty()) record.push_back(2 * record.back());
        } else if (op == "+") {
            int n = record.size();
            if (n >= 2) {
                record.push_back(record[n-1] + record[n-2]);
            }
        } else {
            
            record.push_back(stoi(op));
        }
    }

    int sum = 0;
    for (int score : record) {
        sum += score;
    }

    return sum;
}

int main() {
    vector<string> ops1 = {"5","2","C","D","+"};
    cout << calPoints(ops1) << endl;  // Output: 30

    vector<string> ops2 = {"5","-2","4","C","D","9","+","+"};
    cout << calPoints(ops2) << endl;  // Output: 27

    vector<string> ops3 = {"1","C"};
    cout << calPoints(ops3) << endl;  // Output: 0

    return 0;
}
