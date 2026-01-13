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
    int maxDiameter = 0;

    int diameterRecur(Node* root) {
        if (!root)
            return 0;
    
        int lHeight = diameterRecur(root->left);
        int rHeight = diameterRecur(root->right);
    
        if (lHeight + rHeight > maxDiameter)
            maxDiameter = lHeight + rHeight;
    
        return 1 + max(lHeight, rHeight);
    }
    
    int diameter(Node* root) {
        maxDiameter = 0; 
        diameterRecur(root);
        return maxDiameter;
    }

};

int main(){
    Solution sol;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << sol.diameter(root) << endl;
    return 0;
}