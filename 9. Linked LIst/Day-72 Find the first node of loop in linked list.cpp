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
    int cycleStart(Node* head) {
        if(head == nullptr) return false;
        
        Node* fast = head;
        Node* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                // Step-2 of Floyds cycle detection
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;

    cout << sol.cycleStart(head) << endl;
    return 0;
}