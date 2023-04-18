class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int s = 0;
        int e = 0;
        bool flag = true;
        string hold = "";
        while (s < word1.size() && e < word2.size())
        {
            if (flag)
            {
                hold += word1[s++];
                flag = false;
            }
            else
            {
                hold += word2[e++];
                flag = true;
            }
        }

        while (s < word1.size())
        {
            if (flag)
            {
                hold += word1[s++];
            }
        }
        while (e < word2.size())
        {

            hold += word2[e++];
        }
        return hold;
    }
};