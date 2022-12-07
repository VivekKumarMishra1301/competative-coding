class Solution
{
public:
    bool check(string s, string p)
    {

        return s == p;
    }

    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                if (check(haystack.substr(i, needle.size()), needle))
                {
                    return i;
                }
            }
        }
        return -1;
    }
};