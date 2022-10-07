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
bool isPalindrome(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return true;
    }
    int arr[1000];
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    for (int i = count - 1; i >= 0; i--)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    int st = 0;
    int en = count - 1;
    while (st < en)
    {
        if (arr[st] == arr[en])
        {
            st++;
            en--;
        }
        else
        {
            return false;
        }
    }
    return true;
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}