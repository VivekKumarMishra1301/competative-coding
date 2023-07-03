class job
{
public:
    int start;
    int end;
    int profit;
};

class Solution
{
public:
    static bool compare(job a, job b)
    {
        return a.end < b.end;
    };

    int wjs(vector<job> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        // int maxprof=arr[0].profit;
        vector<int> dp(arr.size());
        dp[0] = arr[0].profit;
        for (int i = 1; i < arr.size(); i++)
        {
            // cout<<arr[i].end<<endl;
            int nonclind = -1;
            int inclu = arr[i].profit;
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i].start >= arr[j].end)
                {
                    nonclind = j;
                    break;
                }
            }
            if (nonclind != -1)
            {
                inclu += dp[nonclind];
            }
            dp[i] = max(dp[i - 1], inclu);
        }
        return dp[arr.size() - 1];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<job> arr(n);
        for (int i = 0; i < n; i++)
        {
            job a;
            a.start = startTime[i];
            a.end = endTime[i];
            a.profit = profit[i];
            arr[i] = a;
        }
        return wjs(arr);
    }
};