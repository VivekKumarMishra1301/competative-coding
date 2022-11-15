#include <iostream>
using namespace std;

#include <vector>
class PriorityQueue
{
    // Declare the data members here

    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (pq.size() == 0)
        {
            return -1;
        }
        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here

        if (pq.size() == 0)
        {
            return -1;
        }
        int parentIndex = 0;
        int max = pq[0];
        int temp = pq[parentIndex];
        pq[parentIndex] = pq[pq.size() - 1];

        pq[pq.size() - 1] = temp;
        pq.pop_back();
        while (parentIndex < pq.size())
        {
            int childIndex1 = 2 * parentIndex + 1;
            int childIndex2 = 2 * parentIndex + 2;
            if (childIndex1 < pq.size() && childIndex2 < pq.size())
            {
                if (pq[childIndex1] > pq[parentIndex] && pq[childIndex1] > pq[childIndex2])
                {
                    temp = pq[childIndex1];
                    pq[childIndex1] = pq[parentIndex];
                    pq[parentIndex] = temp;
                    parentIndex = childIndex1;
                }
                else if (pq[childIndex2] > pq[parentIndex] && pq[childIndex2] > pq[childIndex1])
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

                if (pq[childIndex1] > pq[parentIndex])
                {
                    temp = pq[childIndex1];
                    pq[childIndex1] = pq[parentIndex];
                    pq[parentIndex] = temp;
                    parentIndex = childIndex1;
                }
                else
                {
                    break;
                }
            }
            else if (childIndex2 < pq.size())
            {
                if (pq[childIndex2] > pq[parentIndex])
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
            else
            {
                break;
            }
        }
        return max;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
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
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
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