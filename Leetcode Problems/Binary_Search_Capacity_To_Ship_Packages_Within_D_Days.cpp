class Solution
{
public:
    bool check(vector<int> &weights, int mid, int days)
    {
        int d = 1;
        int sum = weights[0];
        for (int i = 1; i < weights.size(); i++)
        {
            if ((sum + weights[i]) <= mid)
            {
                sum += weights[i];
            }
            else
            {
                sum = weights[i];
                d++;
            }
        }

        if (d <= days)
        {
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0;
        int maxval = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (weights[i] > maxval)
            {
                maxval = weights[i];
            }
        }
        // cout<<sum<<" "<<maxval;
        int st = maxval;
        int end = sum;
        int ans = st;
        while (st <= end)
        {

            int mid = (st + end) / 2;
            if (check(weights, mid, days))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }
};