#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    bool detectLoop(Node* head) {
        if (head == nullptr) return false;

        Node* fast = head;
        Node* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            cout << "Fast at: " << fast->data << ", Slow at: " << slow->data << endl;
            cout<<endl;
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }
        return false;
    }
};

int main() { 
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    cout << (sol.detectLoop(head) ? "Loop detected" : "No loop") << endl;
    return 0; 
}