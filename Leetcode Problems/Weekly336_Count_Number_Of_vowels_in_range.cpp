class Solution
{
public:
    bool isv(char s)
    {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        {
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int hold = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (i >= left && i <= right && i < words.size() && isv(words[i][0]) && isv(words[i][words[i].size() - 1]))
            {
                hold++;
            }
        }
        return hold;
    }
};