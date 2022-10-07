#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head->next==NULL){
        return head;
    }
    if(pos==0){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    if(pos==1){
        Node *temp=head->next;
        head->next=head->next->next;
        delete temp;
        return head;
    }
    
    Node *rec=deleteNodeRec(head->next,pos-1);
    head->next=rec;
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}