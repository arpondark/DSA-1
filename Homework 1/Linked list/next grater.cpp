#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    stack<int> st;
    vector<int> values;

    
    while (head) {
        values.push_back(head->val);
        head = head->next;
    }

    
    result = vector<int>(values.size(), 0);

    
    for (std::vector<int>::size_type i = 0; i < values.size(); ++i) {
        while (!st.empty() && values[st.top()] < values[i]) {
            result[st.top()] = values[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}


ListNode* buildList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : nums) {
        ListNode* node = new ListNode(num);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}


void printVector(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    
    ListNode* head1 = buildList({2, 1, 5});
    vector<int> result1 = nextLargerNodes(head1);
    printVector(result1);  

    
    ListNode* head2 = buildList({2, 7, 4, 3, 5});
    vector<int> result2 = nextLargerNodes(head2);
    printVector(result2);  

    return 0;
} 

/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Convert doubly linked list to vector for processing
vector<int> nextLargerNodes(DListNode* head) {
    vector<int> values;
    while (head) {
        values.push_back(head->val);
        head = head->next;
    }

    vector<int> result(values.size(), 0);
    stack<int> st;

    for (size_t i = 0; i < values.size(); ++i) {
        while (!st.empty() && values[st.top()] < values[i]) {
            result[st.top()] = values[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

// Create a doubly linked list from a vector
DListNode* buildDoublyList(const vector<int>& nums) {
    DListNode* head = nullptr;
    DListNode* tail = nullptr;
    for (int num : nums) {
        DListNode* node = new DListNode(num);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

// Print the result
void printVector(const vector<int>& vec) {
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

int main() {
    // Test Case 1
    DListNode* head1 = buildDoublyList({2, 1, 5});
    vector<int> res1 = nextLargerNodes(head1);
    printVector(res1);  // Output: 5 5 0

    // Test Case 2
    DListNode* head2 = buildDoublyList({2, 7, 4, 3, 5});
    vector<int> res2 = nextLargerNodes(head2);
    printVector(res2);  // Output: 7 0 5 5 0

    return 0;
}

*/
