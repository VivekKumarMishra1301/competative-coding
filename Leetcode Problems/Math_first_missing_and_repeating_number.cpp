class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int k)
    {
        // code here
        // taking sum of whole array;
        long n = k;
        long sum1 = ((n) * (n + 1)) / 2;

        // taking sum of power 2 to get the second eqn
        long sum2 = ((n) * (n + 1) * (2 * n + 1)) / 6;
        // getting equation of x-y i.e x is repeating and y is non repeating
        long arsum = 0;
        for (int i = 0; i < n; i++)
        {
            arsum += (long)arr[i];
        }

        // getting equation of x^2-y^2 to take one another equation to solve two variable eqution
        long arsumsq = 0;
        for (int i = 0; i < n; i++)
        {
            arsumsq += ((long)arr[i] * (long)arr[i]);
        }
        long xminusy = arsum - sum1;
        long xsqminusysq = arsumsq - sum2;
        long xplusy = xsqminusysq / xminusy;
        long x = (xminusy + xplusy) / 2;
        long y = x - xminusy;
        //   y=(arsum-sum1)-x;
        vector<int> hold;
        hold.push_back(x);
        hold.push_back(y);

        return hold;
    }
};