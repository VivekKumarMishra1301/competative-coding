class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1), hash(nums.size());
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && dp[i] < dp[prev] + 1)
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            // maxi=max(maxi,dp[i]);
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        for (int i = 0; i < lis.size(); i++)
        {
            cout << lis[i] << " ";
        }
        return lis;
    }
};