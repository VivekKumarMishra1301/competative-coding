class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        int count = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            sort(words[i].begin(), words[i].end());
            words[i].erase(unique(words[i].begin(), words[i].end()), words[i].end());
            string res = words[i];
            cout << res << " ";
            for (int j = i + 1; j < words.size(); j++)
            {
                sort(words[j].begin(), words[j].end());
                words[j].erase(unique(words[j].begin(), words[j].end()), words[j].end());
                string res2 = words[j];
                if (res == res2)
                {
                    count++;
                }
            }
        }

        return count;
    }
};