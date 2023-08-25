class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        int n = b.size() / a.size();
        int cnt = 1;
        string k = a;
        for (int i = 0; i < n + 2; i++)
        {
            if (a.find(b) != string::npos)
            {
                return cnt;
            }
            a += k;
            cnt++;
        }

        return -1;
    }
};D