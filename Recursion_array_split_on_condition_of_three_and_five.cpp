#include <iostream>
bool helper(int *input, int n, int start, int leftsum, int rightsum)
{

    if (start == n)
    {
        if (leftsum == rightsum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (input[start] % 5 == 0)
    {
        leftsum = leftsum + input[start];
    }
    else if (input[start] % 3 == 0)
    {
        rightsum += input[start];
    }
    else
    {
        return helper(input, n, start + 1, leftsum + input[start], rightsum) || helper(input, n, start + 1, leftsum, rightsum + input[start]);
    }
    return helper(input, n, start + 1, leftsum, rightsum);
}

bool splitArray(int *input, int size)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return helper(input, size, 0, 0, 0);
}

using namespace std;

int main()
{

    int size;
    cin >> size;
    int *input = new int[1 + size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
int t;
cin>>t;
while(t--){
    
}
