class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        double res = myPow(x, n / 2);
        if (n % 2 >= 0)
        {

            if (n % 2 == 0)
            {
                return res * res;
            }
            else
            {
                return x * res * res;
            }
        }
        else
        {
            if (n % 2 == 0)
            {
                return 1 / res * res;
            }
            else
            {
                return 1 / x * res * res;
            }
        }
    }
};