#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if (!head1 || !head2) {
            return head1 ? head1 : head2;
        }

        if (head1->data > head2->data) {
            swap(head1, head2);
        }

        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
};

int main(){
    Solution sol;
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);    
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    Node* result = sol.sortedMerge(head1, head2);
    Node* curr = result;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}