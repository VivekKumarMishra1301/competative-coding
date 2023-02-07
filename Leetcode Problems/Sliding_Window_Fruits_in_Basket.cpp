class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> hold;
        int i = 0;
        int j = 0;
        int num = INT_MIN;
        int res = 0;
        for (i = 0, j = 0; j < fruits.size(); j++)
        {
            hold[fruits[j]]++;
            while (hold.size() > 2)
            {
                if (--hold[fruits[i]] == 0)
                {
                    hold.erase(fruits[i]);
                }
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};