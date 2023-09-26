class Solution
{
public:
    string smallestSubsequence(string s)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        vector<bool> vis(26, false);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (vis[s[i] - 'a'])
            {
                freq[s[i] - 'a']--;
                continue;
            }

            while (!st.empty() && st.top() > s[i] && freq[st.top() - 'a'])
            {
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            freq[s[i] - 'a']--;
            vis[s[i] - 'a'] = true;
        }
        string str = "";
        while (!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};