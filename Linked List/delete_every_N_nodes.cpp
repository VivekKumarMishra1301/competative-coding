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
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	if (M == 0)
	{
		return NULL;
	}
	Node *temp = head;
	int m = M;
	while (temp->next != NULL)
	{
		int count = N;
		if (m == 1)
		{

			Node *move = temp->next;
			while (count != 0 && move != NULL)
			{
				move = move->next;
				count--;
			}
			temp->next = move;
		}
		if (temp->next == NULL)
		{
			break;
		}
		temp = temp->next;
		m--;
		if (m == 0)
		{
			m = M;
		}
	}
	return head;
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}