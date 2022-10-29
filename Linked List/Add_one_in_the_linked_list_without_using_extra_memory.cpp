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
    int carry;
};

Pair add(Node *head)
{
    if (head->next == NULL)
    {
        Pair ans;
        ans.carry = 0;
        head->data = head->data + 1 + ans.carry;

        if (head->data > 9)
        {
            head->data = head->data % 10;
            ans.carry = 1;
        }
        else
        {
            ans.carry = 0;
        }
        ans.head = head;
        return ans;
    }
    Pair smallans = add(head->next);
    Pair ans;
    head->data = head->data + smallans.carry;
    head->next = smallans.head;
    if (head->data > 9)
    {
        head->data = head->data % 10;
        ans.carry = 1;
    }
    else
    {
        ans.carry = 0;
    }
    ans.head = head;

    return ans;
}
Node *NextLargeNumber(Node *head)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Pair smallans = add(head);
    if (smallans.carry == 1)
    {
        Node *newnode = new Node(1);
        newnode->next = smallans.head;
        return newnode;
    }
    else
    {
        return smallans.head;
    }
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
    Node *head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}
