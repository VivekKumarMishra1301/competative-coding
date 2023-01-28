class Solution
{

public:
    unordered_map<string, int> meraMap;
    bool canConcat(string word)
    {
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            string pref = word.substr(0, i + 1);
            string suff = word.substr(i + 1, n);
            if (meraMap.count(pref) != 0 && (meraMap.count(suff) != 0 || canConcat(suff)))
            {
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> hold;
        for (auto i : words)
        {
            meraMap[i]++;
        }

        for (auto i : words)
        {
            if (canConcat(i))
            {
                hold.push_back(i);
            }
        }
        return hold;
    }
};