class Solution
{
public:
    bool isvowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

    int maxVowels(string s, int k)
    {
        map<char, int>meraMap;
        int st = 0;
        int en = 0;
        int maxi = 0;
        while (en < s.size())
        {
            meraMap[s[en]]++;
            if ((en - st + 1) == k)
            {
                int su = 0;
                for (auto i : meraMap)
                {
                    if (isvowel(i.first))
                    {
                        su += i.second;
                    }
                }
                cout << su << " ";
                maxi = max(maxi, su);
                meraMap[s[st++]]--;
            }
            en++;
        }
        if (en - st == k)
        {
            int su = 0;
            for (auto i : meraMap)
            {
                if (isvowel(i.first))
                {
                    su += i.second;
                }
            }
            maxi = max(maxi, su);
        }

        return maxi;
    }
};