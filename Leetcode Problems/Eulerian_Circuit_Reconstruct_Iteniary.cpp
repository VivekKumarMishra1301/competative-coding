class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, multiset<string>> adj;
        vector<string> hold;
        for (auto i : tickets)
        {
            adj[i[0]].insert(i[1]);
        }
        stack<string> st;
        st.push("JFK");
        while (!st.empty())
        {
            string sr = st.top();
            if (adj[sr].size() == 0)
            {
                hold.push_back(sr);
                st.pop();
            }
            else
            {
                auto dst = adj[sr].begin();
                st.push(*dst);
                adj[sr].erase(dst);
            }
        }
        reverse(hold.begin(), hold.end());
        return hold;
    }
};