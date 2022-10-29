#include <iostream>
using namespace std;

#include <stack>

int *stockSpan(int *price, int size)
{
    // Write your code here
    stack<int> stock;
    int *arr = new int[size];
    // int max=0;
    stock.push(0);
    arr[0] = 1;
    for (int i = 1; i < size; i++)
    {
        while (!stock.empty() && price[stock.top()] < price[i])
        {
            stock.pop();
        }
        arr[i] = (stock.empty()) ? (i + 1) : (i - stock.top());
        stock.push(i);
    }
    return arr;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}