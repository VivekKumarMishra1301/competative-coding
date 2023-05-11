class Solution
{
public:
    int connect(int ind1, int ind2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (ind1 == nums1.size() - 1 && ind2 < nums2.size() - 1 && nums1[ind1] == nums2[ind2])
        {
            return 1;
        }
        if (ind1 >= nums1.size() || ind2 >= nums2.size())
        {
            return 0;
        }

        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }

        int pos = 0;
        if (nums1[ind1] == nums2[ind2])
        {
            pos = 1 + connect(ind1 + 1, ind2 + 1, nums1, nums2, dp);
        }
        else
        {
            pos = max(connect(ind1, ind2 + 1, nums1, nums2, dp), connect(ind1 + 1, ind2, nums1, nums2, dp));
        }
        return dp[ind1][ind2] = pos;
    }

    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // return 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, -1));
        return connect(0, 0, nums1, nums2, dp);
    }
};