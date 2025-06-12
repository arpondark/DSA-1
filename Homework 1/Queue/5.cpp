/*
!Implement Stack using Queues
? LeetCode Problem: 225. Implement Stack using Queues

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        tempQ.push(x);
        while(!mainQ.empty()){
            tempQ.push(mainQ.front());
            mainQ.pop();
        }
        swap(mainQ,tempQ);
    }
    
    int pop() {
        int topElement = mainQ.front();
        mainQ.pop();
        return topElement;
        
    }
    
    int top() {
        return mainQ.front();
    }
    
    bool empty() {
        return mainQ.empty();
    }
 private:
    queue<int> mainQ;
    queue<int>tempQ;
};

*/


#include <bits/stdc++.h>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        // Constructor
    }

    void push(int x) {
        q2.push(x);
        // Move all elements from q1 to q2 to maintain LIFO order
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        if (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            return val;
        }
        return -1; // Or throw an error
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Or throw an error
    }

    bool empty() {
        return q1.empty();
    }
};

// Example usage
int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl;    // Output: 2
    cout << myStack.pop() << endl;    // Output: 2
    cout << boolalpha << myStack.empty() << endl; // Output: false
    return 0;
}
