class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        vector<long long> hold(nums.size(), 0);
        map<int, vector<int>> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]].push_back(i);
        }

        for (auto i : meraMap)
        {
            vector<int> k = i.second;
            long long wsum = 0;
            for (int j = 0; j < k.size(); j++)
            {
                long long nm = k[j];
                wsum += nm;
            }

            long long rsum = 0;
            for (int m = 0; m < k.size(); m++)
            {
                long long prcnt = m;
                long long curr = k[m];
                long long res = prcnt * curr - rsum;
                long long nxtcnt = k.size() - (m + 1);
                rsum += curr;
                res = res + (wsum - rsum) - nxtcnt * curr;
                hold[k[m]] = res;
            }
        }

        return hold;
    }
};