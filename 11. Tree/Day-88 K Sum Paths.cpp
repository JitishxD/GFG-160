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
    int countPathsUtil(Node* node, int k, int currSum,
                       unordered_map<int, int>& prefSums) {
        if (node == nullptr) return 0;

        int pathCount = 0;
        currSum += node->data;

        if (currSum == k) pathCount++;

        pathCount += prefSums[currSum - k];

        prefSums[currSum]++;

        pathCount += countPathsUtil(node->left, k, currSum, prefSums);
        pathCount += countPathsUtil(node->right, k, currSum, prefSums);

        prefSums[currSum]--;

        return pathCount;
    }

    int countAllPaths(Node* root, int k) {
        unordered_map<int, int> prefSums;

        return countPathsUtil(root, k, 0, prefSums);
    }
};

int main() {
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(11);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);
    int k = 8;
    cout << sol.countAllPaths(root, k) << endl;

    return 0;
}