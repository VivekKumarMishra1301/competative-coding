class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> hold;
        vector<int> prefix(nums.size(), 0);
        sort(nums.begin(), nums.end());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < queries.size(); i++)
        {
            hold.push_back(upper_bound(prefix.begin(), prefix.end(), queries[i]) - prefix.begin());
        }
        return hold;
    }
};