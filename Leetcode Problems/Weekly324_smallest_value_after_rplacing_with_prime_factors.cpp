class Solution
{
public:
    int smallestValue(int n)
    {

        int sum = 0;
        bool flag = false;
        int i = 2;
        while (i <= n / 2)
        {
            if (n % i == 0)
            {
                sum += i;
                flag = true;
                n /= i;
                continue;
            }
            i++;
        }
        if (n != 1 && flag == 1)
        {
            sum += n;
        }
        if (n == 2 && sum == 4)
        {
            return sum;
        }
        if (flag == 0)
        {
            return n;
        }
        return smallestValue(sum);
    }
};