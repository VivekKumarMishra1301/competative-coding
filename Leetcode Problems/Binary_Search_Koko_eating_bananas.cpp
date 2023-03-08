class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // return 0;
        if (piles.size() == 1)
        {
            if (piles[0] > h)
                if (piles[0] % h)
                    return piles[0] / h + 1;
                else
                    return piles[0] / h;
            else if (piles[0] < h)
                return 1;
            else
                return piles[0];
        }
        int st = 0;
        int en = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (mid == 0)
            {
                return ans;
            }
            int hr = 0;
            for (int i = 0; i < piles.size(); i++)
            {
                if (piles[i] % mid)
                {
                    hr += piles[i] / mid;
                    hr++;
                }
                else
                {
                    hr += piles[i] / mid;
                }
            }
            if (hr <= h)
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
};