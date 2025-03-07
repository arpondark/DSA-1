#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<int> nums;
    int n = 0;
    for(char c : s) {
        if(c == '+') {
            nums.push_back(n);
            n = 0;
        } else {
            n = n * 10 + (c - '0');
        }
    }
    nums.push_back(n);
    bubble(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < nums.size() - 1) {
            cout << "+";
        }
    }
    cout << endl;
    return 0;
}