// bubble sort iterative
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
Node *swap(Node *prev, Node *curr, Node *forw)
{
    if (prev == NULL)
    {
        Node *get = curr->next->next;
        Node *start = curr->next;
        curr->next->next = curr;
        curr->next = get;
        return start;
    }
    prev->next = forw;
    curr->next = forw->next;
    forw->next = curr;
    return forw;
}

Node *bubbleSort(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        if (head->next->data < head->data)
        {
            Node *get = head->next->next;
            head->next->next = head;
            head->next = NULL;
            return get;
        }
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *forw = curr->next;
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (curr->data > forw->data)
            {
                curr = swap(prev, curr, forw);
                if (prev == NULL)
                    head = curr;
            }
            prev = curr;
            curr = curr->next;
            forw = curr->next;
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
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}