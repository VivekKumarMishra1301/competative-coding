class Solution
{
public:
    string removeStars(string s)
    {

        string hold = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (hold.size() != 0 && s[i] == '*')
            {
                hold.pop_back();
            }
            else if (s[i] != '*')
            {
                hold.push_back(s[i]);
            }
        }

        return hold;
    }
};