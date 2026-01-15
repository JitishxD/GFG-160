#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
   public:
    Node* buildTreeRecur(unordered_map<int, int>& mp, vector<int>& preorder,
                         int& preIndex, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex];
        preIndex++;

        Node* root = new Node(rootVal);

        int index = mp[rootVal];

        root->left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
        root->right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        int preIndex = 0;
        Node* root =
            buildTreeRecur(mp, preorder, preIndex, 0, inorder.size() - 1);

        return root;
    }
};

int main() {
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};

    Solution sol;
    Node* root = sol.buildTree(inorder, preorder);

    
    return 0;
}