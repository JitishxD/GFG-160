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
    Node* rotate(Node* head, int k) {
        if (!head || !head->next) 
            return head;

        Node* t = head;
        Node* last = head;

        while (last->next != nullptr) {
            last = last->next;
        }

        while (k--) {
            t = head;
            head = head->next;

            t->next = nullptr;
            last->next = t;
            last = t;
        }

        return head;
    }
};


int main(){
    Solution sol;
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int k = 2;
    Node* result = sol.rotate(head, k);
    Node* curr = result;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}