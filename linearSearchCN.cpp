int linearSearch(int *arr, int n, int x)
{
    // Write your code here

    int add = -1;

    if (n >= 0 && n <= 100000)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                add = i;
                break;
            }
        }
    }

    if (add == -1)
    {
        return add;
    }
    else
    {
        return add;
    }
}