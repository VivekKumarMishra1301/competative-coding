class Solution
{
public:
    bool checkAP(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = arr[0] - arr[1];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i - 1] - arr[i] != diff)
            {
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            int s = l[i];
            int e = r[i];
            vector<int> hold;
            for (int j = s; j <= e; j++)
            {
                hold.push_back(nums[j]);
            }
            ans.push_back(checkAP(hold));
        }
        return ans;
    }
};