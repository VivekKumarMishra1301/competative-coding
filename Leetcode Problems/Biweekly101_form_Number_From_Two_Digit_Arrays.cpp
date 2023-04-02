class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        map<int, int> meraMap;
        map<int, int> teraMap;
        for (int i = 0; i < nums1.size(); i++)
        {
            meraMap[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (meraMap.find(nums2[i]) != meraMap.end())
            {
                return nums2[i];
            }
        }

        if (nums1[0] == nums2[0])
        {
            return nums1[0];
        }
        if (nums1[0] < nums2[0])
        {
            return nums1[0] * 10 + nums2[0];
        }
        else
        {
            return nums2[0] * 10 + nums1[0];
        }
    }
};