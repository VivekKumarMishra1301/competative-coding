class Solution
{
public:
    vector<int> distinctDifferenceArray(vector<int> &nums)
    {
        int totdist = 0;
        vector<int> pref;
        vector<int> suff(nums.size(), 0);
        map<int, int> meraMap;
        map<int, int> teraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]]++;
            pref.push_back(meraMap.size());
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (teraMap.find(nums[i]) != teraMap.end())
            {
                suff[i] = teraMap.size();
                continue;
            }
            teraMap[nums[i]]++;
            suff[i] = teraMap.size() - 1;
            cout << suff[i] << " ";
        }
        cout << endl;
        totdist = meraMap.size();
        vector<int> hold;
        for (int i = 0; i < nums.size(); i++)
        {
            hold.push_back(pref[i] - suff[i]);
        }
        return hold;
    }
};