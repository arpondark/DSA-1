/* //!232. Implement Queue using Stacks
class MyQueue {
    stack<int> s1;
    stack<int>s2;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        return res;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input, output;

public:
    MyQueue() {
        // Constructor
    }

    // Push element to back of queue
    void push(int x) {
        input.push(x);
    }

    // Remove element from front of queue
    int pop() {
        if (output.empty()) {
            // Move elements from input to output only when output is empty
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }

    // Get front element
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Check if queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

// Example usage
int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << endl;   // Output: 1
    cout << myQueue.pop() << endl;    // Output: 1
    cout << boolalpha << myQueue.empty() << endl; // Output: false
    return 0;
}
