class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
    {
        if (nums1 == nums2)
        {
            return 0;
        }
        else if (nums1 != nums2 && k == 0)
            return -1;

        long long ghatana = 0;
        long long ginti = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (abs(nums1[i] - nums2[i]) % k != 0)
                return -1;
            ghatana = ghatana + (nums1[i] - nums2[i]);
            ginti = ginti + abs(nums1[i] - nums2[i]) / k;
        }
        if (ghatana != 0)
        {
            return -1;
        }
        return ginti / 2;
    }
};