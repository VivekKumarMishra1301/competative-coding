class Solution
{
public:
    int hash[1001];
    int find(vector<int> &nums, int k, int ind)
    {
        if (ind == nums.size())
        {
            return 1;
        }
        int pick = 0;
        if ((nums[ind] - k) < 0 || hash[nums[ind] - k] == 0)
        {
            hash[nums[ind]]++;
            pick = find(nums, k, ind + 1);
            hash[nums[ind]]--;
        }
        int notpick = find(nums, k, ind + 1);
        return pick + notpick;
    }

    int beautifulSubsets(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<int> hold;
        memset(hash, 0, sizeof(hash));

        return find(nums, k, 0) - 1;
        // return cnt-1;
    }
};