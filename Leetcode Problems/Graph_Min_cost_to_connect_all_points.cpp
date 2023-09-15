class Solution
{
public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<int> minDist(n, 0);
        int hold = 0;
        minDist[0] = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            minDist[i] = dist(points[0][0], points[0][1], points[i][0], points[i][1]);
        }

        for (int i = 1; i < n; i++)
        {
            auto it = min_element(minDist.begin(), minDist.end());
            hold += *it;
            int ind = it - minDist.begin();
            *it = INT_MAX;
            for (auto i = 0; i < n; i++)
            {
                if (minDist[i] == INT_MAX)
                {
                    continue;
                }
                minDist[i] = min(minDist[i], dist(points[i][0], points[i][1], points[ind][0], points[ind][1]));
            }
        }
        return hold;
    }
};