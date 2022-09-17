#include <iostream>
using namespace std;
void helper(int input[], int n, int output[], int m)
{
    if (n <= 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    helper(input + 1, n - 1, output, m);
    int newout[100000];
    for (int i = 0; i < m; i++)
    {
        newout[i] = output[i];
    }
    newout[m] = input[0];
    helper(input + 1, n - 1, newout, m + 1);
}
void printSubsetsOfArray(int input[], int size)
{
    int output[100000];
    int m = 0;
    helper(input, size, output, m);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
