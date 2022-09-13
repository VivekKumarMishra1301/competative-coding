#include <iostream>
using namespace std;

void print2DArray(int **input, int row, int col)
{
    // Write your code here
    int k = row;
    int l = col;
    int m = 0;
    while (k)
    {
        for (int j = 0; j < k; j++)
        {

            for (int i = 0; i < col; i++)
            {
                cout << input[m][i] << " ";
            }
            cout << endl;
        }
        k--;
        m++;
    }
}
