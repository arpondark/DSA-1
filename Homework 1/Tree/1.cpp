#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* pre;  // To track the previous node during the traversal
    int maxFrequency, count;  // To track the maximum frequency and current count
    vector<int> modes;  // To store the modes

    vector<int> findMode(TreeNode* root) {
        pre = nullptr;
        maxFrequency = 0;
        count = 0;
        modes.clear();
        inorderTraversal(root);  // Perform in-order traversal
        return modes;
    }

    // Helper function for in-order traversal
    void inorderTraversal(TreeNode* node) {
        if (!node) return;

        inorderTraversal(node->left);  // Visit left child
        
        // Process the current node
        if (pre != nullptr && pre->val == node->val) {
            count++;  // Increment count for duplicates
        } else {
            count = 1;  // Reset count for a new value
        }

        // Update mode list and max frequency
        if (count > maxFrequency) {
            modes.clear();  // Reset modes list as we found a new maximum frequency
            modes.push_back(node->val);
            maxFrequency = count;
        } else if (count == maxFrequency) {
            modes.push_back(node->val);  // Add the value to the modes list if frequency matches
        }

        pre = node;  // Set the current node as the previous node for the next comparison

        inorderTraversal(node->right);  // Visit right child
    }
};

// Function to create a binary tree from a level order array
TreeNode* insertLevelOrder(vector<int>& arr, TreeNode* root, int i, int n) {
    if (i < n) {
        if (arr[i] == -1) return nullptr;  // -1 represents null nodes
        
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Input for tree: [1, null, 2, 2]
    vector<int> input = {1, -1, 2, 2};  // -1 represents null for the left child of 1

    // Build the tree from the input array
    TreeNode* root = nullptr;
    root = insertLevelOrder(input, root, 0, input.size());

    Solution solution;
    vector<int> modes = solution.findMode(root);

    // Output the modes
    cout << "Modes: ";
    for (int mode : modes) {
        cout << mode << " ";
    }
    cout << endl;

    return 0;
}
