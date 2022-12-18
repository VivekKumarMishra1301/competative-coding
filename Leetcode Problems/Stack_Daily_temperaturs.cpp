// 1st approach

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> hold;
        int maxind = temperatures.size() - 1;
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {

                hold.push_back(0);
                st.push(i);
                continue;
            }

            while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                hold.push_back(0);
                st.push(i);
                continue;
            }

            hold.push_back(st.top() - i);
            st.push(i);
        }

        reverse(hold.begin(), hold.end());

        return hold;
    }
};