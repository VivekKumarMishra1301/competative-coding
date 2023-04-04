class Solution
{
public:
    int partitionString(string s)
    {
        bool *arr = new bool[26];
        for (int i = 0; i < 26; i++)
        {
            arr[i] = false;
        }
        int cnt = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == true)
            {
                cnt++;
                arr = new bool[26];
                for (int j = 0; j < 26; j++)
                {
                    arr[j] = false;
                }
                arr[s[i] - 'a'] = true;
            }
            else
            {
                arr[s[i] - 'a'] = true;
            }
        }
        return cnt;
    }
};