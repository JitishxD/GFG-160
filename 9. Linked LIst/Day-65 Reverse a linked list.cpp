#include <bits/stdc++.h>

using namespace std;

struct Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
};

int main(){
    Solution sol;
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node* result = sol.reverseList(head);
    Node* curr = result;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}