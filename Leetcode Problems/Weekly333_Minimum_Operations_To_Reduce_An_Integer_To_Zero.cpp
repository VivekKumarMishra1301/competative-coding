class Solution
{
public:
    int minOperations(int n)
    {
        if (n == 1 || n == 2)
        {
            return 1;
        }
        int i = 1;
        int k = 2;
        while (k < n)
        {
            i++;
            k = k * 2;
        }

        if (k == n)
        {
            return 1;
        }
        int p = i - 1;
        int q = i;
        int d = min(n - pow(2, p), pow(2, q) - n);
        return 1 + minOperations(d);
    }
};