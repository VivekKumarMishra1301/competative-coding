class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_map<string, int> meraMap;
        for (auto i : dictionary)
        {
            meraMap[i]++;
        }

        string cn = "";
        vector<string> hold;
        for (int i = 0; sentence[i] != '\0'; i++)
        {
            if (sentence[i] == ' ')
            {
                hold.push_back(cn);
                cn = "";
            }
            else
            {
                cn += sentence[i];
            }
        }
        if (cn.size() != 0)
        {
            hold.push_back(cn);
        }

        for (int i = 0; i < hold.size(); i++)
        {
            string w = hold[i];
            string t = "";
            for (int j = 0; j < w.size(); j++)
            {
                t += w[j];
                if (meraMap.find(t) != meraMap.end())
                {
                    hold[i] = t;
                    break;
                }
            }
        }

        string snt = "";
        for (int i = 0; i < hold.size(); i++)
        {
            string w = hold[i];
            snt += w;
            snt += ' ';
        }
        snt.pop_back();
        return snt;
    }
};