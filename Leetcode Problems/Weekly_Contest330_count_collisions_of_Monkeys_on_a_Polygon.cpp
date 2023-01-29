class Solution
{
public:
    long long int caculateP(long long int i, long long int j)
    {
        if (j == 0)
        {

            return 1;
        }

        if (j % 2 == 1)
        {

            return (2 * caculateP(2, j - 1)) % 1000000007;
        }
        long long int finalP = caculateP(2, j / 2);
        return (finalP * finalP) % 1000000007;
    }

    int monkeyMove(int n)
    {
        long long int gh = 1;
        gh = caculateP(2, n);
        gh = gh - 2;

        if (gh < 0)
            gh = gh + 1000000007;

        return gh;
    }
};