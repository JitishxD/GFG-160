#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
   public:
    void removeLoop(Node* head) {
        if (head == nullptr || head->next == nullptr) return;

        Node *slow = head, *fast = head;
        slow = slow->next;
        fast = fast->next->next;

        while (fast && fast->next) {
            if (slow == fast) break;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If loop exists
        if (slow == fast) {
            slow = head;
            if (slow == fast)
                while (fast->next != slow) fast = fast->next;
            else {
                while (slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
        }
    }
};

int main() {
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    sol.removeLoop(head);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}