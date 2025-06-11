/* LeetCode 1700 - Number of Students Unable to Eat Lunch 
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2);
        for (int student : students) {
            count[student]++;
        }
        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0) {
                return count[0] + count[1];
            }
            count[sandwich]--;
        }
        return 0;
    }
};
*/

#include <bits/stdc++.h>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> count(2);  // count[0] for circular, count[1] for square

    // Count student preferences
    for (int student : students) {
        count[student]++;
    }

    // Iterate over sandwiches
    for (int sandwich : sandwiches) {
        if (count[sandwich] == 0) {
            // No students left who want this type
            return count[0] + count[1];
        }
        count[sandwich]--;
    }

    // All students are able to eat
    return 0;
}

int main() {
    // Sample input
    vector<int> students = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};

    int result = countStudents(students, sandwiches);
    cout << "Number of students who can't eat: " << result << endl;

    return 0;
}
