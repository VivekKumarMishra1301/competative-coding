vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    // Write your code here.
    int x = 0;
    int y = 0;
    int xo = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xo = xo ^ nums[i];
        xo = xo ^ (i + 1);
    }

    int setbit = 0;
    while (1)
    {
        if ((xo & (1 << setbit)) != 0)
        {
            break;
        }
        setbit++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if ((nums[i] & (1 << setbit)) != 0)
        {
            x ^= nums[i];
        }
        else
        {
            y ^= nums[i];
        }
    }
    for (int i = 1; i <= nums.size(); i++)
    {
        if ((i & (1 << setbit)) != 0)
        {
            x ^= i;
        }
        else
        {
            y ^= i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x)
        {
            cnt++;
        }
    }
    if (cnt == 2)
        return {x, y};
    else
        return {y, x};
}