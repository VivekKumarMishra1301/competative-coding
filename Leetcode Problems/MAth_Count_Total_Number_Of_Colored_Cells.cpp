class Solution
{
public:
    long long coloredCells(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        long long hold = 1;
        int l = 1;
        for (int i = 2; i <= n; i++)
        {
            l += 2;
            hold += l;
        }
        long long k = 1;
        l = 1;
        for (int i = 2; i <= n - 1; i++)
        {
            l += 2;
            k += l;
        }
        return hold + k;
    }
};