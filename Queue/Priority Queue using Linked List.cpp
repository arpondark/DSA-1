// C++ code to implement Priority Queue 
// using Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
  
    Node(int x, int p) {
        data = x;
        priority = p;
        next = NULL;
    }
};

// Return the value at head
int peek(Node* head) {

    // Return the data of the node at the head of the list
    return head->data;
}

// Removes the element with the highest priority from the list
Node* pop(Node* head) {

    // Store the current head node in a temporary variable
    Node* temp = head;

    // Move the head to the next node in the list
    head = head->next;

    // Free the memory of the removed head node
    delete temp;

    // Return the new head of the list
    return head;
}

// Function to push according to priority
Node* push(Node* head, int d, int p) {
    Node* start = head;

    // Create new Node with the given data and priority
    Node* temp = new Node(d, p);

    // Special Case: Insert the new node before the head
    // if the list is empty or the head has lower priority
    if (head == NULL || head->priority > p) {

        // Insert the new node before the head
        temp->next = head;
        head = temp;
    }
    else {

        // Traverse the list to find the correct position
        // to insert the new node based on priority
        while (start->next != NULL &&
               start->next->priority < p) {
            start = start->next;
        }

        // Insert the new node at the found position
        temp->next = start->next;
        start->next = temp;
    }
    return head;
}

// Function to check if the list is empty
int isEmpty(Node* head) {
    return (head == NULL);
}

// Driver code
int main() {

    Node* pq = new Node(4, 1);

    pq = push(pq, 5, 2);
    pq = push(pq, 6, 3);
    pq = push(pq, 7, 0);

    while (!isEmpty(pq)) {
        cout << " " << peek(pq);
        pq = pop(pq);
    }
    return 0;
}