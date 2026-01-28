#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
   public:
    void correctBSTUtil(Node* root, Node*& first, Node*& middle, Node*& last,
                        Node*& prev) {
        if (root == nullptr) return;

        correctBSTUtil(root->left, first, middle, last, prev);

        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else last = root;
        }

        prev = root;

        correctBSTUtil(root->right, first, middle, last, prev);
    }

    void correctBST(Node* root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr,
             *prev = nullptr;
        correctBSTUtil(root, first, middle, last, prev);
        if (first && last) swap(first->data, last->data);
        else if (first && middle) swap(first->data, middle->data);
    }
};

int main() {
    Solution sol;
    Node* root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(12);

    sol.correctBST(root);
    return 0;
}