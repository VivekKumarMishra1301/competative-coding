class Solution
{
public:
    int find(long long num, vector<int> &potions, long long success)
    {
        int st = 0;
        int en = potions.size() - 1;
        long long san = potions[en];
        if (num * san < success)
        {
            return en + 1;
        }
        int ans = en + 1;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            long long num2 = potions[mid];
            if (num * num2 >= success)
            {
                ans = min(ans, mid);
                en = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> hold;
        for (int i = 0; i < spells.size(); i++)
        {
            hold.push_back(potions.size() - find(spells[i], potions, success));
        }
        return hold;
    }
};