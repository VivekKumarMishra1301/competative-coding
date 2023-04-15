class Solution
{
public:
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        vector<int> hold;
        for (int i = 0; i < grid[0].size(); i++)
        {
            long md = 1;
            for (int j = 0; j < grid.size(); j++)
            {
                int dig = 0;
                if (grid[j][i] == 0)
                {
                    // md=max(md,1);
                    continue;
                }
                if (grid[j][i] < 0)
                {
                    dig++;
                    while (grid[j][i] < 0)
                    {
                        dig++;
                        grid[j][i] /= 10;
                    }
                }
                else
                {
                    while (grid[j][i] > 0)
                    {
                        dig++;
                        grid[j][i] /= 10;
                    }
                }
                if (dig > md)
                {
                    md = dig;
                }
            }
            hold.push_back(md);
        }
        return hold;
    }
};