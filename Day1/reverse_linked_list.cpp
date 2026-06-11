#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* createLinkedList(vector<int>& arr) {

    if(arr.empty())
        return NULL;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for(int i = 1; i < arr.size(); i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}

Node* reverseList(Node* head) {

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {

        Node* forward = curr->next;

        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}

void printList(Node* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    vector<int> arr = {1,2,3,4,5};

    Node* head = createLinkedList(arr);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}