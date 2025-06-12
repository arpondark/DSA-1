/* //!Leetcode 933 Number Of Recent Calls
 * 
 * Design a queue that supports push and pop operations in the following way:
 * 
 * - push(x) -- Pushes the element x to the back of the queue.
 * - pop() -- Removes the element from the front of the queue and returns it.
 * - last() -- Returns the element at the front of the queue without removing it.
 * - size() -- Returns the number of elements in the queue.
 * 
 * The queue should be implemented using a linked list.
 */
/*
 class RecentCounter {
public:
queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

*/


#include <bits/stdc++.h>
using namespace std;

// Global queues to simulate the stack
queue<int> q1;  // Main queue
queue<int> q2;  // Helper queue

// Push element x to the top of the stack
void push(int x) {
    // Push to q2, then move all elements from q1 to q2
    // Finally swap q1 and q2
    q2.push(x);
    
    // Move all elements from q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    // Swap q1 and q2 so q1 always contains our stack
    swap(q1, q2);
}

// Remove and return the element on top of the stack
int pop() {
    if (q1.empty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    
    int topElement = q1.front();
    q1.pop();
    return topElement;
}

// Return the element on top of the stack without removing it
int top() {
    if (q1.empty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    
    return q1.front();
}

// Check if the stack is empty
bool empty() {
    return q1.empty();
}

int main() {
    // Simulating the example
    push(1);
    push(2);
    
    cout << top() << endl;    // Output: 2
    cout << pop() << endl;    // Output: 2
    cout << (empty() ? "true" : "false") << endl; // Output: false
    
    // Additional tests
    cout << top() << endl;    // Output: 1
    cout << pop() << endl;    // Output: 1
    cout << (empty() ? "true" : "false") << endl; // Output: true
    
    // Test with more elements
    push(5);
    push(10);
    push(15);
    cout << "Top: " << top() << endl;  // Output: 15
    cout << "Pop: " << pop() << endl;  // Output: 15
    cout << "Top: " << top() << endl;  // Output: 10
    
    return 0;
}
