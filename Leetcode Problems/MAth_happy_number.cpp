class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 7)
        {
            return true;
        }
        if (n == 1)
        {
            return true;
        }
        if ((int)(log10(n) + 1) == 1)
        {
            return false;
        }

        int ans = 0;
        while (n > 0)
        {
            int r = n % 10;
            ans += r * r;
            n /= 10;
        }
        return isHappy(ans);
    }
};