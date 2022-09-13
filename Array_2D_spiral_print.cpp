#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    // Write your code here
    int count = 0;
    int rs = 0, cs = 0, ce = nCols - 1, re = nRows - 1;

    while (count < nRows * nCols)
    {
        for (int i = rs; i <= ce; i++)
        {
            cout << input[cs][i] << " ";
            count++;
        }
        if (count >= nRows * nCols)
        {
            break;
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            cout << input[i][ce] << " ";
            count++;
        }
        if (count >= nRows * nCols)
        {
            break;
        }
        ce--;
        for (int i = ce; i >= cs; i--)
        {
            cout << input[re][i] << " ";
            count++;
        }
        if (count >= nRows * nCols)
        {
            break;
        }
        re--;
        for (int i = re; i >= rs; i--)
        {
            cout << input[i][cs] << " ";
            count++;
        }
        cs++;
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
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}