class Solution
{
public:
    map<int, int> meraMap;

    void dfs(vector<int> &nums, int &cnt, int ind)
    {
        if (meraMap.find(nums[ind]) == meraMap.end())
        {
            cnt++;
            meraMap[nums[ind]]++;
            dfs(nums, cnt, nums[ind]);
        }
    }

    int arrayNesting(vector<int> &nums)
    {
        int maxi = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (meraMap.find(nums[i]) == meraMap.end())
            {
                int cnt = 0;
                dfs(nums, cnt, i);
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }
};