class Solution
{
public:
    bool canMinimize(vector<int> &nums, int p, int diff)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] <= diff)
            {
                p--;
                i++;
            }
        }
        if (p <= 0)
            return true;
        return false;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int hold = nums[nums.size() - 1] - nums[0];

        int st = 0;
        int en = hold;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (canMinimize(nums, p, mid))
            {
                hold = mid;
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }

        return hold;
    }
};