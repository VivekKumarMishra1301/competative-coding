class Solution
{
public:
    long long minc(vector<int> &nums, vector<int> &cost, long long median)
    {
        long long hold = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            hold += abs(nums[i] - median) * (1ll * cost[i]);
        }
        return hold;
    }

    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        vector<pair<long long, long long>> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr.push_back({nums[i], cost[i]});
        }
        sort(arr.begin(), arr.end());
        long long s = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            s += arr[i].second;
        }

        long long median = arr[0].first;
        long long tot = 0;
        int i = 0;
        while (tot < (s + 1) / 2 && i < nums.size())
        {
            tot += arr[i].second;
            median = arr[i].first;
            i++;
        }

        return minc(nums, cost, median);
    }
};