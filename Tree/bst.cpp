#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
};


Node* insertNode(Node* root, int v) {
    if (root == NULL) {
        Node* n = new Node;
        n->val = v;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    if (v < root->val) {
        root->left = insertNode(root->left, v);
    } else {
        root->right = insertNode(root->right, v);
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << "->";
    inorder(root->right);
}


int findMin(Node* root) {
    if (root == NULL) {
        return -1;
    }
    if (root->left == NULL) {
        return root->val;
    }
    return findMin(root->left);
}


int findMax(Node* root) {
    if (root == NULL) {
        return -1;
    }
    if (root->right == NULL) {
        return root->val;
    }
    return findMax(root->right);
}

// Search for a value in BST
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->val == key) return true;
    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
}


Node* findParent(Node* root, int key) {
    if (root == NULL || root->val == key) return NULL;

    if ((root->left && root->left->val == key) || (root->right && root->right->val == key)) {
        return root;
    }

    if (key < root->val)
        return findParent(root->left, key);
    else
        return findParent(root->right, key);
}

int main() {
    int key;
    cin >> key;
    Node* root = NULL;
    int values[] = {15, 8, 22, 5, 11, 17, 27, 10, 14, 9, 12, 13};
    for (int v : values) {
        root = insertNode(root, v);
    }

    
    inorder(root);
    cout << endl;

   
    cout << "Min: " << findMin(root) << endl;
    cout << "Max: " << findMax(root) << endl;

    
    if (search(root, key)) {
        cout << key << " found in tree" << endl;
        Node* parent = findParent(root, key);
        if (parent)
            cout << "parent of " << key << " is: " << parent->val << endl;
        else
            cout << key << "no parent" << endl;
    } else {
        cout << key << "404! not found" << endl;
    }

    return 0;
}
