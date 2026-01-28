#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
   public:
    vector<int> serialize(Node* root) {
        vector<int> arr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // If curr node is null,
            // append -1 to result.
            if (curr == nullptr) {
                arr.push_back(-1);
                continue;
            }
            arr.push_back(curr->data);

            q.push(curr->left);
            q.push(curr->right);
        }

        return arr;
    }

    Node* deSerialize(vector<int>& arr) {
        if (arr[0] == -1) return nullptr;

        // create root node and push it into queue
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // If left node is not null
            if (arr[i] != -1) {
                Node* left = new Node(arr[i]);
                curr->left = left;
                q.push(left);
            }
            i++;

            // If right node is not null
            if (arr[i] != -1) {
                Node* right = new Node(arr[i]);
                curr->right = right;
                q.push(right);
            }
            i++;
        }

        return root;
    }
};

int main() {
    Solution sol;
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    vector<int> arr = sol.serialize(root);
    Node* res = sol.deSerialize(arr);

    cout << "Serialized array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Root of deserialized tree: " << res->data << endl;
    
    return 0;
}