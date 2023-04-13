class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        int i = 0;
        int j = 0;
        stack<int> st;
        while (i < pushed.size() && j < popped.size())
        {
            if (!st.empty() && st.top() == popped[j])
            {
                while (!st.empty() && st.top() == popped[j])
                {

                    j++;
                    st.pop();
                }
                st.push(pushed[i]);
                i++;
            }
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        cout << i << j;
        if (j == popped.size())
        {
            return true;
        }

        while (!st.empty() && j < popped.size())
        {
            if (st.top() != popped[j])
            {
                return false;
            }
            else
            {
                st.pop();
                j++;
            }
        }
        return true;
    }
};