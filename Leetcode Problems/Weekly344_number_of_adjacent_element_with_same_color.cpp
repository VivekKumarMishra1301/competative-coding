class Solution
{
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries)
    {

        vector<int> hold(n, 0);
        vector<int> nums(n, 0);
        int cnt = 0;
        for (auto j : queries)
        {

            int i = j[0];
            int col = j[1];

            if (nums[i] != 0 && i + 1 < nums.size() && (nums[i] == nums[i + 1]))
            {
                cnt--;
            }
            if (nums[i] != 0 && i - 1 >= 0 && (nums[i] == nums[i - 1]))
            {
                cnt--;
            }
            nums[i] = col;
            if (i - 1 >= 0 && (nums[i] == nums[i - 1]))
            {
                cnt++;
            }
            if (i + 1 < nums.size() && (nums[i] == nums[i + 1]))
            {
                cnt++;
            }
            hold[i] = cnt;
        }

        return hold;
    }
};