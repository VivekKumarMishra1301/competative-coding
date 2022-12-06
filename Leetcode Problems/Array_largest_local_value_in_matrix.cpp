class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> hold(grid.size() - 2, vector<int>(grid.size() - 2, 0));
        int n = grid.size();
        int strow = 0;
        int enrow = 2;
        int stcol = 0;
        int encol = 2;

        while (enrow < n && encol < n)
        {

            int max = INT_MIN;
            for (int i = strow; i <= enrow; i++)
            {
                for (int j = stcol; j <= encol; j++)
                {
                    if (grid[i][j] > max)
                    {
                        max = grid[i][j];
                    }
                }
            }

            hold[strow][stcol] = max;

            stcol++;

            encol++;
            if (encol == n)
            {
                stcol = 0;
                encol = 2;
                strow++;
                enrow++;
            }
        }
        return hold;
    }
};