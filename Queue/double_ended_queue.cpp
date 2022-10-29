// C++ implementation of De-queue using circular
// array
#include <iostream>
using namespace std;

class Deque
{
    // Complete this class
public:
    int *get;
    int size;
    int capacity;
    int frontindex;
    int nextindex;

    Deque(int s)
    {
        get = new int[s];
        capacity = s;
        size = 0;
        frontindex = -1;
        nextindex = 0;
    }
    void insertFront(int data)
    {
        if (size == capacity)
        {
            cout << "-1" << endl;
            return;
        }
        if (size == 0)
        {
            get[nextindex] = data;
            frontindex = 0;
            nextindex++;
            ;
            size++;
            return;
        }
        if (frontindex != 0)
        {
            get[--frontindex] = data;
            size++;
        }
        else
        {

            frontindex = capacity - 1;
            get[frontindex] = data;
            size++;
        }
    }
    void insertRear(int data)
    {
        if (size == capacity)
        {
            cout << "-1" << endl;
            return;
        }
        if (size == 0)
        {
            get[nextindex] = data;
            frontindex = 0;
            nextindex++;
            size++;
            return;
        }

        get[nextindex] = data;
        size++;
        nextindex = (nextindex + 1) % capacity;
    }
    void deleteFront()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return;
        }
        if (size == 1)
        {
            nextindex = 0;
            frontindex = -1;
            size--;
            return;
        }
        frontindex = (frontindex + 1) % capacity;
        size--;
    }
    void deleteRear()
    {
        if (size == 0)
        {
            cout << "-1" << endl;
            return;
        }
        if (frontindex == nextindex)
        {
            nextindex = -1;
            frontindex = -1;
            return;
        }
        nextindex--;
        size--;
    }
    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        return get[frontindex];
    }
    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        return get[nextindex - 1];
    }
};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }

    return 0;
}
