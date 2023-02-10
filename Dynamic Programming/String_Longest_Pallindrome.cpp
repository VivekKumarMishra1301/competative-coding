class Solution
{
public:
    int longestPalindrome(string s)
    {
        if (s.size() == 1)
        {
            return 1;
        }
        unordered_map<char, int> meraMap;
        for (auto i : s)
        {
            meraMap[i]++;
        }

        bool flag = false;
        int num = 0;
        for (auto i : meraMap)
        {
            if (i.second % 2 == 0)
            {
                num += i.second;
            }
            else
            {
                flag = true;
                num += (i.second - 1);
            }
        }
        if (flag)
        {
            return num + 1;
        }
        else
        {
            return num;
        }
    }
};