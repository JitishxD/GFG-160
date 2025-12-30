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
    Node* reverseKnodes(Node* start, int k) {
        Node* prev = nullptr;
        Node* curr = start;

        while (k-- && curr) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* curr = head;
        Node* prevGroupTail = nullptr;

        while (curr) {
            int count = 0;
            Node* temp = curr;
            while (temp && count < k) {
                temp = temp->next;
                count++;
            }

            Node* groupHead = curr;
            Node* nextGroupHead = temp;

            Node* newGroupHead = reverseKnodes(groupHead, count);

            if (!prevGroupTail)
                head = newGroupHead;
            else
                prevGroupTail->next = newGroupHead;

            groupHead->next = nextGroupHead;

            prevGroupTail = groupHead;
            curr = nextGroupHead;
        }

        return head;
    }
};


int main(){
    Solution sol;
    Node* head = new Node(1);

    for(int i = 2; i <= 10; i++) {
        Node* newNode = new Node(i);
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    int k = 3;
    Node* result = sol.reverseKGroup(head, k);
    Node* curr = result;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    
    return 0;
}