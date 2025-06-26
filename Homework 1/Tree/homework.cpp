#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if the tree is a BST
bool isBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if (!root) return true;

    // Check if the current node's value is within the allowed range
    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
        return false;
    }

    // Recur for left and right subtrees with updated min and max
    return isBST(root->left, minNode, root) && isBST(root->right, root, maxNode);
}

// Function to find the predecessor of a node
TreeNode* findPredecessor(TreeNode* root, int key) {
    TreeNode* predecessor = nullptr;
    while (root) {
        if (key <= root->val) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

// Function to find the successor of a node
TreeNode* findSuccessor(TreeNode* root, int key) {
    TreeNode* successor = nullptr;
    while (root) {
        if (key >= root->val) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

// Function to find the sibling of a node
TreeNode* findSibling(TreeNode* root, int key) {
    if (!root) return nullptr;

    TreeNode* parent = nullptr;
    while (root) {
        if (key < root->val) {
            parent = root;
            root = root->left;
        } else if (key > root->val) {
            parent = root;
            root = root->right;
        } else {
            if (parent && parent->left && parent->left->val == key) {
                return parent->right;
            } else if (parent && parent->right && parent->right->val == key) {
                return parent->left;
            }
            return nullptr;
        }
    }
    return nullptr;
}

// Helper function to insert nodes in the tree (BST)
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int main() {
    // Create the binary search tree
    TreeNode* root = nullptr;
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 20);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 15);
    insertNode(root, 25);

    // Task 1: Check if the tree is a BST
    if (isBST(root, nullptr, nullptr)) {
        cout << "The tree is a Binary Search Tree (BST)" << endl;
    } else {
        cout << "The tree is NOT a Binary Search Tree (BST)" << endl;
    }

    // Task 2: Find Predecessor
    int key = 7;
    TreeNode* predecessor = findPredecessor(root, key);
    if (predecessor) {
        cout << "Predecessor of " << key << " is " << predecessor->val << endl;
    } else {
        cout << "No predecessor found for " << key << endl;
    }

    // Task 3: Find Successor
    TreeNode* successor = findSuccessor(root, key);
    if (successor) {
        cout << "Successor of " << key << " is " << successor->val << endl;
    } else {
        cout << "No successor found for " << key << endl;
    }

    // Task 4: Find Sibling
    TreeNode* sibling = findSibling(root, key);
    if (sibling) {
        cout << "Sibling of " << key << " is " << sibling->val << endl;
    } else {
        cout << "No sibling found for " << key << endl;
    }

    return 0;
}
