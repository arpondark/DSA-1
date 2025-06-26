#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;  // To keep track of the previous node in in-order traversal
    int minDiff = INT_MAX;     // infinity to find the minimum difference

    // Function to perform in-order traversal and calculate the minimum difference
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDiff;
    }

    // Helper function to perform in-order traversal
    void inorderTraversal(TreeNode* root) {
        if (!root) return;
        
        // Traverse the left subtree
        inorderTraversal(root->left);

        // Process the current node
        if (prev) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;  // Update the previous node to the current one

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
};

// Helper function to insert nodes in a Binary Search Tree (BST)
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
    // Create a BST and test the solution
    TreeNode* root = nullptr;
    root = insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);

    Solution solution;
    int result = solution.getMinimumDifference(root);

    cout << "Minimum absolute difference in BST: " << result << endl;

    return 0;
}
