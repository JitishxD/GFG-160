#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    void levelOrderRec(Node* root, int level, vector<vector<int>>& res) {
        if (root == nullptr) return;
        if (res.size() <= level) res.push_back({});

        res[level].push_back(root->data);

        // Tail recursion for left and right subtrees
        levelOrderRec(root->left, level + 1, res);
        levelOrderRec(root->right, level + 1, res);
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res; 
        levelOrderRec(root, 0, res);
        return res;
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
    vector<vector<int>> result = sol.levelOrder(root);
    for (const auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}