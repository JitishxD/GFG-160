#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int kthSmallest(Node* root, int k) {
        int count = 0;
    
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                count++;
                if (count == k) return curr->data;
                curr = curr->right;
            } else {
                Node* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }
    
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    count++;
                    if (count == k) return curr->data;
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    int k = 3;
    cout << sol.kthSmallest(root, k) << endl;
    
    return 0;
}
