#include <bits/stdc++.h>

using namespace std;

struct Node {
   public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
   public:
    Node* reverseLL(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;

        while (curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        int n1 = 0, n2 = 0;
        Node* t1 = head1;
        Node* t2 = head2;

        while (t1 != nullptr && t1->data == 0) t1 = t1->next;
        while (t2 != nullptr && t2->data == 0) t2 = t2->next;

        Node* t1_rev = reverseLL(t1);
        Node* t2_rev = reverseLL(t2);

        Node* dummy = new Node(0);
        Node* ans = dummy;
        int carry = 0;

        while (t1_rev || t2_rev || carry) {
            int currSum = carry;

            if (t1_rev) {
                currSum += t1_rev->data;
                t1_rev = t1_rev->next;
            }

            if (t2_rev) {
                currSum += t2_rev->data;
                t2_rev = t2_rev->next;
            }

            carry = currSum / 10;
            ans->next = new Node(currSum % 10);
            ans = ans->next;
        }

        // reverse result to correct order
        return reverseLL(dummy->next);
    }
};

int main() {
    Solution sol;
    // head1 = 8 5 1 
    // head2 = 7 4 7 
    // sum = 1 5 9 8
    Node* head1 = new Node(8);
    head1->next = new Node(5);
    head1->next->next = new Node(1);

    Node* head2 = new Node(7);
    head2->next = new Node(4);
    head2->next->next = new Node(7);

    // Add two lists
    Node* result = sol.addTwoLists(head1, head2);

    // Print result
    Node* curr = result;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
