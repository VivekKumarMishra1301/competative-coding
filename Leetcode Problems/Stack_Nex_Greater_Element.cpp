#include <bits/stdc++.h>

vector<int> nextGreaterElement(vector<int> input)
{
    // Write your code here
    vector<int> hold(input.size(), -1);
    stack<int> st;
    int j = 0;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            hold[i] = -1;
            st.push(input[i]);
            continue;
        }
        while (!st.empty() && input[i] >= st.top())
        {
            st.pop();
        }
        if (st.empty())
        {
            hold[i] = -1;
        }
        else
        {
            hold[i] = st.top();
        }
        st.push(input[i]);
    }
    return hold;
}
