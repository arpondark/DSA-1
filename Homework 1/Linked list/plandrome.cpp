#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}

// Check if linked list is a palindrome
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    ListNode* secondHalf = reverse(slow);

    // Step 3: Compare halves
    ListNode* firstHalf = head;
    ListNode* secondCopy = secondHalf; // To restore later if needed

    while (secondHalf) {
        if (firstHalf->val != secondHalf->val)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Optional: reverse(secondCopy); // Restore if original structure matters

    return true;
}

// Helper to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(8);

    cout << "List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "It's a palindrome." << endl;
    else
        cout << "Not a palindrome." << endl;

    return 0;
}
/*#include <iostream>
using namespace std;

struct DoublyNode {
    int val;
    DoublyNode* next;
    DoublyNode* prev;
    DoublyNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Function to check palindrome in a doubly linked list
bool isDoublyPalindrome(DoublyNode* head) {
    if (!head || !head->next) return true;

    // Find tail
    DoublyNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    // Compare from both ends
    while (head != tail && head->prev != tail) {
        if (head->val != tail->val)
            return false;
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

// Print doubly linked list
void printDoubly(DoublyNode* head) {
    while (head) {
        cout << head->val << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example: 1 <-> 2 <-> 3 <-> 2 <-> 1
    DoublyNode* head = new DoublyNode(1);
    head->next = new DoublyNode(2); head->next->prev = head;
    head->next->next = new DoublyNode(3); head->next->next->prev = head->next;
    head->next->next->next = new DoublyNode(2); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DoublyNode(1); head->next->next->next->next->prev = head->next->next->next;

    cout << "Doubly Linked List: ";
    printDoubly(head);

    if (isDoublyPalindrome(head))
        cout << "It's a palindrome." << endl;
    else
        cout << "Not a palindrome." << endl;

    return 0;
}
*/
