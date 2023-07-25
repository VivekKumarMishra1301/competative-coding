class Solution
{
public:
    bool find132pattern(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> mini;
        int minele = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            minele = min(minele, arr[i]);
            mini.push_back(minele);
        }

        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > mini[i])
            {
                while (!st.empty() && st.top() <= mini[i])
                {
                    st.pop();
                }
                if (!st.empty() && st.top() < arr[i])
                {
                    return true;
                }
                st.push(arr[i]);
            }
        }
        return false;
    }
};