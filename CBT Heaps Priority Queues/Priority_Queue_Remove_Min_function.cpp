#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        // Write your code here
        if (pq.size() == 0)
        {
            return 0;
        }
        if (pq.size() == 1)
        {
            int min = pq[pq.size() - 1];
            pq.pop_back();
            return min;
        }
        int temp = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq[pq.size() - 1] = temp;
        int min = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < pq.size())
        {
            int childIndex1 = 2 * parentIndex + 1;
            int childIndex2 = 2 * parentIndex + 2;
            if (childIndex1 < pq.size() && childIndex2 < pq.size())
            {
                if (pq[childIndex1] < pq[parentIndex] && pq[childIndex1] < pq[childIndex2])
                {
                    temp = pq[childIndex1];
                    pq[childIndex1] = pq[parentIndex];
                    pq[parentIndex] = temp;
                    parentIndex = childIndex1;
                }
                else if (pq[childIndex2] < pq[parentIndex] && pq[childIndex2] < pq[childIndex1])
                {
                    temp = pq[childIndex2];
                    pq[childIndex2] = pq[parentIndex];
                    pq[parentIndex] = temp;
                    parentIndex = childIndex2;
                }
                else
                {
                    break;
                }
            }
            else if (childIndex1 < pq.size())
            {
                temp = pq[childIndex1];
                pq[childIndex1] = pq[parentIndex];
                pq[parentIndex] = temp;
                parentIndex = childIndex1;
            }
            else if (childIndex2 < pq.size())
            {
                temp = pq[childIndex2];
                pq[childIndex2] = pq[parentIndex];
                pq[parentIndex] = temp;
                parentIndex = childIndex2;
            }
            else
            {
                break;
            }
        }
        return min;
    }
};

int main()
{
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMin
            cout << pq.getMin() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMin() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}