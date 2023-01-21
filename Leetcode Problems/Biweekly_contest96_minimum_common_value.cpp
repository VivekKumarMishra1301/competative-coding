class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> meraMap;
        for (auto i : nums2)
        {
            meraMap[i]++;
        }

        sort(nums1.begin(), nums1.end());
        for (auto i : nums1)
        {
            if (meraMap.count(i) != 0)
            {
                return i;
            }
        }
        return -1;
    }
};