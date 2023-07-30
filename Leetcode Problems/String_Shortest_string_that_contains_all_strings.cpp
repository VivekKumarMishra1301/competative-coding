class Solution
{
public:
    string minstr(string a, string b)
    {
        return (a.size() < b.size() || (a.size() == b.size() && a < b)) ? a : b;
    }

    string merge(string a, string b)
    {
        if (b.find(a) != string::npos)
        {
            return b;
        }

        for (int i = 0; i < a.size(); i++)
        {
            string s1 = a.substr(i);
            string s2 = b.substr(0, s1.size());
            if (s1 == s2)
            {
                return a + b.substr(s1.size());
            }
        }
        return a + b;
    }
    string solve(string &a, string &b, string &c)
    {
        string t1 = merge(a, b), t2 = merge(b, a);
        string res1 = minstr(merge(t1, c), merge(c, t1));
        string res2 = minstr(merge(t2, c), merge(c, t2));
        return minstr(res1, res2);
    }

    string minimumString(string a, string b, string c)
    {
        string res = minstr(solve(a, b, c), solve(b, c, a));
        return minstr(res, solve(c, a, b));
    }
};