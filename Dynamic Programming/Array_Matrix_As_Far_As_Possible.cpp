class Solution
{
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

    bool isValid(int r, int c, int n)
    {
        return (r >= 0 && c >= 0 && r < n && c < n);
    }

    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<vector<int>> pq;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dist[i][j] = 0;
                    pq.push({i, j});
                }
            }
        }
        int hold = 0;
        while (!pq.empty())
        {
            vector<int> vect = pq.front();
            pq.pop();
            int r = vect[0];
            int c = vect[1];
            if (grid[r][c] == 0)
            {
                hold = max(hold, dist[r][c]);
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (isValid(nr, nc, n) && -1 == dist[nr][nc])
                {
                    dist[nr][nc] = dist[r][c] + 1;
                    pq.push({nr, nc});
                }
            }
        }
        return hold == 0 ? -1 : hold;
    }
};