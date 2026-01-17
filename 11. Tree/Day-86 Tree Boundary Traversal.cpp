#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    bool isLeaf(Node* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void collectLeft(Node* root, vector<int>& ans) {
        if (root == nullptr || isLeaf(root)) return;

        ans.push_back(root->data);
        if (root->left) collectLeft(root->left, ans);

        else if (root->right) collectLeft(root->right, ans);
    }

    void collectLeaves(Node* root, vector<int>& ans) {
        if (root == nullptr) return;
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        collectLeaves(root->left, ans);
        collectLeaves(root->right, ans);
    }

    void collectRight(Node* root, vector<int>& ans) {
        if (root == nullptr || isLeaf(root)) return;
        if (root->right) collectRight(root->right, ans);

        else if (root->left) collectRight(root->left, ans);

        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;

        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);

        collectLeft(root->left, ans);
        collectLeaves(root, ans);
        collectRight(root->right, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> boundary = sol.boundaryTraversal(root);
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;
}