class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int prof = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            prof = max(prof, cost);
            mini = min(prices[i], mini);
        }
        return prof;
    }
};


if (len == 0)
		return false;

	
	if (len == 1)
	return ((num[0]-'0')%8 == 0);

	
	if (len == 2)
	return (((num[len-2]-'0')*10 + (num[len-1]-'0'))%8 == 0);

	
	
                int l = num[len-1] - '0';
                int sl = num[len-2] - '0';
                int tl = num[len-3] - '0';

                return ((tl*100 + sl*10 + l) % 8 == 0);