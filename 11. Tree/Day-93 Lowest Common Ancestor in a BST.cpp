#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        while (root != nullptr) {
            if (root->data > n1->data && root->data > n2->data)
                root = root->left;

            else if (root->data < n1->data && root->data < n2->data)
                root = root->right;

            else break;
        }

        return root;
    }
};

int main() {
    Node* root = new Node(16);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(18);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);

    Node* n1 = root->left->right->left;
    Node* n2 = root->left->right->right;
    Solution sol;
    Node* lca = sol.LCA(root, n1, n2);
    cout << "LCA of " << n1->data << " and " << n2->data << " is " << lca->data << endl;
    return 0;
}