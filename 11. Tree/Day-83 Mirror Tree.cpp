#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void mirror(Node* root) {
        if (root == nullptr) return;
    
        queue<Node*> q;
        q.push(root);
    
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
    
            swap(curr->left, curr->right);
    
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    
    int getHeight(Node* root, int h) {
        if (root == nullptr) return h - 1;
        return max(getHeight(root->left, h + 1), getHeight(root->right, h + 1));
    }
    
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    sol.mirror(root);

    return 0;
}