class Solution
{
public:
    int minDeletions(string s)
    {

        vector<int> freq(26, 0);
        for (auto i : s)
        {
            freq[i - 'a']++;
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        // unordered_map<int,int>meraMap;
        // for(int i=0;i<26;i++){
        //     meraMap[freq[i]]++;
        // }
        int hold = 0;

        for (int i = 0; i < 26; i++)
        {
            cout << freq[i] << " ";
        }

        for (int i = 1; i < 26; i++)
        {
            if (freq[i - 1] != 0 && freq[i] == freq[i - 1])
            {
                freq[i]--;
                hold++;
            }
            else if (freq[i] < freq[i - 1])
            {
                continue;
            }
            else if (freq[i] > freq[i - 1])
            {
                if (freq[i - 1] == 0)
                {
                    hold += freq[i];
                    freq[i] = 0;
                    continue;
                }
                if (freq[i - 1] == 1)
                {
                    hold += freq[i];
                    freq[i] = 0;
                    continue;
                }
                hold += (freq[i] - freq[i - 1] + 1);
                freq[i] = freq[i - 1] - 1;
            }
            else
            {
                hold += freq[i];
                freq[i] = 0;
            }
        }
        return hold;
    }
};