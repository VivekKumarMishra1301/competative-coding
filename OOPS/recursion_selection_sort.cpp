#include <iostream>

using namespace std;

void selection_sort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    int min = arr[0];
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            ind = i;
        }
    }
    swap(arr[0], arr[ind]);
    selection_sort(arr + 1, n - 1);
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    cout << "Enter the size of an array" << endl;
    int n;
    cin >> n;
    cout << "Enter the element in an array" << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selection_sort(arr, n);

    // print kara lena hai array ko

    print(arr, n);
    return 0;
}