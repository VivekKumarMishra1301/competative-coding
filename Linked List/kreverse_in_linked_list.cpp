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
class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Pair reverse(Node *head,int k){
    if(head==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    int count =1;
    Pair smallLL;
    smallLL.head=head;
    smallLL.tail=head;
    while(count<k&&smallLL.tail->next!=NULL){
        smallLL.tail=smallLL.tail->next;
        count++;
    }
    Pair ans2;
    ans2.head=smallLL.tail->next;
    smallLL.tail->next=NULL;
    Pair ans=reverseLL_2(smallLL.head);
    smallLL.head=ans.head;
    smallLL.tail=ans.tail;
    smallLL.tail->next= reverse(ans2.head,k).head;
    return smallLL;
}
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k==0||head==NULL){
        return head;
    }
    return reverse(head,k).head;
  
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}