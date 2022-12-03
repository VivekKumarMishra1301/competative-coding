class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> hold;
        int max = INT_MIN;
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > max)
            {
                max = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if ((candies[i] + extraCandies) >= max)
            {
                hold.push_back(true);
            }
            else
            {
                hold.push_back(false);
            }
        }
        return hold;
    }
};