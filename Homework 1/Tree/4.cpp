#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return (!root || root->val == val) ? root : (root->val < val ? searchBST(root->right, val) : searchBST(root->left, val));
    }
};
int main() {
    // Create a binary search tree for testing
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    int val = 45;  // for seach 
    
    Solution solution;
    TreeNode* result = solution.searchBST(root, val);
    
    
    if (result) {
        cout << "Node found with value: " << result->val << endl;
    } else {
        cout << "Node not found" << endl;
    }
    
    return 0;
}