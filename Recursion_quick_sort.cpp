#include <iostream>
using namespace std;
void quickSort(int input[], int size)
{
    /* Don't write main().
       Don't read input, it is passed as function argument.
       Change in the given array itself.
       Taking input and printing output is handled automatically.
    */
    if (size == 0 || size == 1)
    {
        return;
    }
    int pivot = input[0];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] < pivot)
        {
            count++;
        }
    }
    int temp = input[count];
    input[count] = input[0];
    input[0] = temp;
    int i = 0, j = size - 1;
    while (i < count)
    {
        if (input[i] < pivot)
        {
            i++;
        }
        else if (input[j] > pivot)
        {
            j--;
        }
        else
        {
            int temp1 = input[j];
            input[j] = input[i];
            input[i] = temp1;
            i++;
            j--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }
    //     int pi=count;
    //     int arr1[500],arr2[500];
    //     for(int i=0;i<pi;i++){

    //         arr1[i]=input[i];

    //     }

    //     int l=0;
    //     for(int i=pi+1;i<size;i++){
    //         arr2[l++]=input[i];
    //     }
    //     int size2=size-pi-1;

    //     quickSort(arr1,pi);
    //     quickSort(arr2,size2);

    //     for(int i=0;i<pi;i++){
    //         input[i]=arr1[i];
    //     }
    //     int p=0;
    //     for(int i=pi+1;i<size;i++){
    //         input[i]=arr2[p++];
    //     }
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
