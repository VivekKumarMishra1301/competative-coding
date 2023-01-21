class Solution
{
public:
    void findsub(vector<int> &nums, vector<vector<int>> &hold, vector<int> &hold1, int n, int ind)
    {
        // if(ind==n){
        // vector<vector<int>>::iterator it = find(hold.begin(), hold.end(), hold1);
        if (hold1.size() > 1)
        { //&&it==hold.end()
            hold.push_back(hold1);
        }
        // return ;
        // }
        unordered_set<int> set;
        for (int i = ind; i < nums.size(); i++)
        {

            if ((hold1.size() == 0 || nums[i] >= hold1[hold1.size() - 1]) && set.find(nums[i]) == set.end())
            {
                hold1.push_back(nums[i]);

                findsub(nums, hold, hold1, n, i + 1);

                hold1.pop_back();
                set.insert(nums[i]);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<vector<int>> hold;
        vector<int> hold1;
        findsub(nums, hold, hold1, nums.size(), 0);
        return hold;
    }
};