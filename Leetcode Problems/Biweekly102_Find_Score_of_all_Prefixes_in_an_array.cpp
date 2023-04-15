class Solution
{
public:
    vector<long long> findPrefixScore(vector<int> &nums)
    {
        vector<long long> hold;
        long long rs = 0;
        long long badka = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            long long nnum = (long long)nums[i];
            // badka=max(badka,nums[i]);
            if (badka < nnum)
            {
                badka = nnum;
            }
            long long naya = nnum + badka;
            rs += naya;
            hold.push_back(rs);
        }
        return hold;
    }
};