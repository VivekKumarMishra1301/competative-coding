class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {

        map<char, int> meraMap;
        for (int i = 0; i < vals.size(); i++)
        {

            meraMap[chars[i]] = vals[i];
        }

        int first_max = 0;

        int sec_max = 0;

        int maxi = 0;
        int temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            temp = max(temp, maxi);
            if (meraMap.find(s[i]) != meraMap.end())
            {
                maxi += meraMap[s[i]];
            }
            else
            {
                maxi += (s[i] - 'a' + 1);
            }
            if (maxi < 0)
            {
                maxi = 0;
            }
        }
        temp = max(temp, maxi);
        return temp;
    }
};