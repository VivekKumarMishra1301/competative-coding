class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }
        if ((count + 1) < pattern.size())
        {
            return false;
        }

        if (s.size() < pattern.size())
        {
            return false;
        }
        else if (s.size() == pattern.size() && s.size() != 1)
        {
            return false;
        }
        vector<string> hold;
        int m = 0;
        string match = "";
        unordered_map<char, string> meraMap;
        unordered_map<string, char> teraMap;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {

                if (meraMap.count(pattern[m]) == 0)
                {

                    meraMap[pattern[m]] = match;
                    match = "";
                    m++;
                }
                else if (meraMap[pattern[m]] == match)
                {
                    match = "";
                    m++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                match += s[i];
            }
        }
        // for(auto i:meraMap){
        //     cout<<i.first<< " "<<i.second<<" ";
        // }
        if (meraMap.count(pattern[m]) == 0)
        {

            meraMap[pattern[m]] = match;
            match = "";
            m = 0;
        }
        else if (meraMap[pattern[m]] == match)
        {
            match = "";
            m = 0;
        }
        else
        {
            return false;
        }

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == ' ')
            {

                cout << pattern[m] << " ";
                if (teraMap.count(match) == 0)
                {

                    teraMap[match] = pattern[m];
                    match = "";
                    m++;
                }
                else if (teraMap[match] == pattern[m])
                {
                    match = "";
                    m++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                match += s[i];
            }
        }

        if (teraMap.count(match) == 0)
        {

            return true;
        }
        else if (teraMap[match] == pattern[m])
        {
            return true;
        }
        else
        {
            return false;
        }

        return true;
    }
};