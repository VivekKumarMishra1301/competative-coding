#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivote = arr[start];
    int count = 0;

    // kitni value pivote se choti hai
    for (int i = start + 1; i <= end; i++)
    {
        if (pivote >= arr[i])
        {
            count++;
        }
    }
    int pivote_index = count;

    swap(arr[pivote_index], arr[start]);
    pivote = arr[count];
    int i = start;
    int j = end;

    while (i < pivote_index && j > pivote_index)
    {
        if (arr[i] <= pivote)
        {
            i++;
        }
        else if (arr[j] <= pivote)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else
        {
            j--;
        }
    }
    return pivote_index;
}

void quick_sort(int *arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    else
    {
        int p = partition(arr, start, end);

        // left me check karna
        quick_sort(arr, start, p - 1);

        // right me check karna hai
        quick_sort(arr, p + 1, end);
    }
}

int main()
{
    cout << "Enter the size of an array" << endl;
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the element in an array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    cout << "Sorted Array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}