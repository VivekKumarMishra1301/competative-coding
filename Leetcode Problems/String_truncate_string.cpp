class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                k--;
            }
            if (k == 0)
            {
                break;
            }
            str = str + s[i];
        }
        return str;
    }
};