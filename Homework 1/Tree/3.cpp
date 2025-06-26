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
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;  // Set to store the values we have seen so far
        return dfs(root, k, seen);
    }
    
   
    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;
        
        // Check if k - node->val exists in the seen set
        if (seen.find(k - node->val) != seen.end())  return true; // found value of k - node->val
              
        
        
       
        seen.insert(node->val);
        
        // Traverse the left and right subtrees
        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};

int main() {
    // Create the BST for testing
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    int k = 9;  // Target sum to check
    
    Solution solution;
    bool result = solution.findTarget(root, k);
    
    // Output the result
    if (result) {
        cout << "True" << endl;  // If a pair is found
    } else {
        cout << "False" << endl;  // If no pair is found
    }

    return 0;
}
