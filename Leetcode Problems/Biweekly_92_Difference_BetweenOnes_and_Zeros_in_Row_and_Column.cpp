class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        vector<int> onerow;
        vector<int> onecol;
        vector<int> zerorow;
        vector<int> zerocol;
        for (int i = 0; i < grid.size(); i++)
        {
            int onecount = 0;
            int zerocount = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    zerocount++;
                }
                else
                {
                    onecount++;
                }
            }
            onerow.push_back(onecount);
            zerorow.push_back(zerocount);
        }
        int colsize = grid[0].size();
        for (int i = 0; i < colsize; i++)
        {
            int onecount = 0;
            int zerocount = 0;
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j][i] == 0)
                {
                    zerocount++;
                }
                else
                {
                    onecount++;
                }
            }

            onecol.push_back(onecount);
            zerocol.push_back(zerocount);
        }

        vector<vector<int>> hold;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> hold1;
            for (int j = 0; j < grid[i].size(); j++)
            {
                int ans = onerow[i] + onecol[j] - zerorow[i] - zerocol[j];
                hold1.push_back(ans);
            }
            hold.push_back(hold1);
        }

        return hold;
    }
};