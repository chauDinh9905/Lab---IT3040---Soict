#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* tmp = head;
    Node* node = new Node(data);
    node -> next = tmp;
    head = node;
    return node;
}

// print the list content on a line
void print(Node* head) {
    while(head != NULL){
       cout << head -> data << " ";
       head = head -> next;
   }
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *nextp = curr -> next;

    while(curr != NULL){
       curr -> next = prev;
       prev = curr;
       curr = nextp;
   }
return prev;
}
  
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    
    cout << "Reversed list: ";
    print(head);

    return 0; 
}