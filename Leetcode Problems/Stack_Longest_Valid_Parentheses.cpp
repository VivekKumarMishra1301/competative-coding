class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<char> st1;
        stack<int> st2;
        st2.push(-1);
        int hold = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st1.push(s[i]);
                st2.push(i);
            }
            else
            {
                if (!st1.empty())
                {
                    st1.pop();
                    st2.pop();
                    hold = max(hold, i - st2.top());
                }
                else
                {
                    st2.push(i);
                }
            }
        }
        return hold;
    }
};