class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> effort(n, vector<int>(heights[0].size(), INT_MAX));
        effort[0][0] = 0;
        int dr[] = {0, -1, 1, 0};
        int dc[] = {1, 0, 0, -1};
        while (!pq.empty())
        {
            pair<int, pair<int, int>> tp = pq.top();
            pq.pop();
            int diff = tp.first;
            int r = tp.second.first;
            int c = tp.second.second;
            if (r == heights.size() - 1 && c == heights[0].size() - 1)
            {
                return diff;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= n || nr < 0 || nc >= heights[0].size() || nc < 0)
                {
                    continue;
                }
                int eff = max(diff, abs(heights[r][c] - heights[nr][nc]));
                if (eff < effort[nr][nc])
                {
                    effort[nr][nc] = eff;
                    pq.push({eff, {nr, nc}});
                }
            }
        }
        return 0;
    }
};