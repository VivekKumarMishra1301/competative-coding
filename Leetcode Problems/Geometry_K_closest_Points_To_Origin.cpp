class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < points.size(); i++)
        {
            mp[(pow(points[i][0], 2) + pow(points[i][1], 2))].push_back({points[i][0], points[i][1]});
        }

        vector<vector<int>> hold;
        for (auto i : mp)
        {
            if (!k)
            {
                return hold;
            }
            vector<pair<int, int>> l = i.second;
            for (int j = 0; j < l.size(); j++)
            {
                k--;
                vector<int> m(2);
                m[0] = l[j].first;
                m[1] = l[j].second;
                hold.push_back(m);
            }
        }
        return hold;
    }
};