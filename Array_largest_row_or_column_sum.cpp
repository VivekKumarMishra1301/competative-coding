#include <iostream>
using namespace std;

/*
You can use minimum value of integer as -2147483647 and
maximum value of integer as 2147483647
*/
void findLargest(int **input, int nRows, int mCols)
{
    // Write your code here
    int ind1 = 0, ind2 = 0;
    int max1 = 0;

    int max2 = 0;

    for (int i = 0; i < mCols; i++)
    {
        int sum1 = 0;
        for (int j = 0; j < nRows; j++)
        {
            sum1 = sum1 + input[j][i];
        }
        if (sum1 > max1)
        {
            ind1 = i;
            max1 = sum1;
        }
    }
    // cout<<max1;
    for (int i = 0; i < mCols; i++)
    {
        int sum2 = 0;
        for (int j = 0; j < nRows; j++)
        {
            sum2 = sum2 + input[i][j];
        }
        if (sum2 > max2)
        {
            ind2 = i;
            max2 = sum2;
        }
    }
    if (nRows != 0)
    {

        if (max2 >= max1)
        {
            cout << "row"
                 << " " << ind2 << " " << max2;
        }
        else
        {
            cout << "column"
                 << " " << ind1 << " " << max1;
        }
    }
    else
    {
        cout << "row"
             << " " << ind2 << " "
             << "-2147483648";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}