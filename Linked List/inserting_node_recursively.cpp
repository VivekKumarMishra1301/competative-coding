#include <iostream>

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(i==0){
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
        return head;
    }
    if(head==NULL){
        return head;
    }
    if(i==1){
        Node *temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    
    Node *rec=insertNode(head->next,i-1,data);
    head->next=rec;
    return head;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}