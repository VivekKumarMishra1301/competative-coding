class Solution
{
public:
    string lexo(string s, string t)
    {
        int st = 0;
        while (st < s.size() && st < t.size())
        {
            if ((s[st] == t[st]))
            {
                st++;
                continue;
            }
            else if (s[st] > t[st])
            {
                return s;
            }
            else
            {
                return t;
            }
        }
        return s;
    }

    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> meraMap;
        for (int i = 0; i < messages.size(); i++)
        {
            int cnt = 1;
            for (int j = 0; j < messages[i].size(); j++)
            {
                if (messages[i][j] == ' ')
                {
                    cnt++;
                }
            }
            // cout<<cnt<<" ";
            meraMap[senders[i]] += cnt;
        }

        string larg = senders[0];
        int maxi = meraMap[senders[0]];
        for (auto i : meraMap)
        {
            cout << i.first << " " << i.second << endl;
            if (i.second > maxi)
            {
                maxi = i.second;
                larg = i.first;
            }
            else if (i.second == maxi)
            {
                larg = lexo(i.first, larg);
                // cout<<s;
            }
        }
        return larg;
    }
};