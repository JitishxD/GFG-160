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
    bool dfs(Node* root, unordered_set<int>& st, int target) {
        if (root == nullptr) return false;

        if (st.find(target - root->data) != st.end()) return true;

        st.insert(root->data);

        return dfs(root->left, st, target) || dfs(root->right, st, target);
    }

    bool findTarget(Node* root, int target) {
        unordered_set<int> st;
        return dfs(root, st, target);
    }
};

int main() {
    Solution sol;
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);
    int target = 12;

    cout << sol.findTarget(root, target);
    return 0;
}