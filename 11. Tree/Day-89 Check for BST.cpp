#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
   public:
    bool isBSTUtil(Node* node, int min, int max) {
        if (node == nullptr) return true;

        if (node->data < min || node->data > max) return false;

        return isBSTUtil(node->left, min, node->data - 1) &&
               isBSTUtil(node->right, node->data + 1, max);
    }

    bool isBST(Node* root) { return isBSTUtil(root, INT_MIN, INT_MAX); }
};
int main() {
    Solution sol;
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    cout << (sol.isBST(root) ? "Is BST" : "Not a BST") << endl;

    return 0;
}