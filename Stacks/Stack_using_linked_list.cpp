#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    // Define the data members
    Node *head;
    int size;

public:
    Stack()
    {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        return size;
        // Implement the getSize() function
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
        // Implement the isEmpty() function
    }

    void push(int element)
    {
        // Implement the push() function
        Node *get = new Node(element);
        if (head == NULL)
        {
            head = get;
        }
        else
        {
            get->next = head;
            head = get;
        }
        size++;
    }
    int pop()
    {
        // Implement the pop() function
        if (head == NULL)
        {
            return -1;
        }
        int value = head->data;
        Node *get = head;
        head = head->next;
        size--;
        delete get;
        return value;
    }

    int top()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
        // Implement the top() function
    }
};

int main()
{
    Stack st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}