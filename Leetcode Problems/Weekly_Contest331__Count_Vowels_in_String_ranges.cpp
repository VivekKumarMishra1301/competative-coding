class Solution
{
public:
    bool isVow(char ch) { return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'); }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> cond;
        for (int i = 0; i < words.size(); i++)
        {
            if (isVow(words[i][0]) && isVow(words[i][words[i].size() - 1]))
            {
                cond.push_back(1);
            }
            else
            {
                cond.push_back(0);
            }
        }

        vector<int> pref;
        int sum = 0;
        for (int i = 0; i < cond.size(); i++)
        {
            sum += cond[i];
            pref.push_back(sum);

            cout << pref[i] << " ";
        }

        vector<int> hold;

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
            {
                hold.push_back(pref[queries[i][1]]);
            }
            else
            {
                hold.push_back(pref[queries[i][1]] - (pref[queries[i][0] - 1]));
            }
        }
        return hold;
    }
};