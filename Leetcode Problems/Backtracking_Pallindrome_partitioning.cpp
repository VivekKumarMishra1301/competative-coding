class Solution
{
public:
    bool isPallindrome(string s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void part(string s, vector<vector<string>> &hold, vector<string> &res, int ind)
    {
        if (ind == s.size())
        {
            hold.push_back(res);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (isPallindrome(s, ind, i))
            {
                res.push_back(s.substr(ind, i - ind + 1));
                part(s, hold, res, i + 1);
                res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> hold;
        vector<string> res;
        part(s, hold, res, 0);
        return hold;
    }
};