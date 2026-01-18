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
    int findMaxSumRec(Node* root, int& ans) {
        if (root == NULL) return 0;

        int l = max(0, findMaxSumRec(root->left, ans));
        int r = max(0, findMaxSumRec(root->right, ans));

        ans = max(ans, l + r + root->data);

        return root->data + max(l, r);
    }

    int findMaxSum(Node* root) {
        int ans = root->data;
        findMaxSumRec(root, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << sol.findMaxSum(root);
    return 0;
}