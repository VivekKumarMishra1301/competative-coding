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
Node *evenAfterOdd(Node *head)
{
    // write your code here
    Node *oddhead = NULL;
    Node *evenhead = NULL;
    Node *temp = head;
    Node *head2 = NULL;
    Node *head1 = NULL;

    if (head == NULL)
    {
        return head;
    }
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenhead == NULL)
            {
                head2 = temp;
                evenhead = temp;
                temp = temp->next;
            }
            else
            {
                evenhead->next = temp;
                evenhead = evenhead->next;
                temp = temp->next;
            }
        }
        else
        {
            if (oddhead == NULL)
            {
                head1 = temp;
                oddhead = temp;
                temp = temp->next;
            }
            else
            {
                oddhead->next = temp;
                oddhead = oddhead->next;
                temp = temp->next;
            }
        }
    }
    if (oddhead == NULL)
    {
        evenhead->next = NULL;
        return head2;
    }
    else if (evenhead == NULL)
    {
        oddhead->next = NULL;
        return head1;
    }
    else
    {

        oddhead->next = head2;
        evenhead->next = NULL;

        return head1;
    }
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
        head = evenAfterOdd(head);
        print(head);
    }
    return 0;
}