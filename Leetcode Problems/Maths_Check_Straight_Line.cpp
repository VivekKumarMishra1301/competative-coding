class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &c)
    {
        // double m=(double)/;
        int y1 = c[0][1];
        int x1 = c[0][0];
        for (int i = 1; i < c.size() - 1; i++)
        {
            int x = c[i][0];
            int y = c[i][1];
            if (((y - y1) * (c[c.size() - 1][0] - c[0][0])) != ((c[c.size() - 1][1] - c[0][1]) * (x - x1)))
            {
                return false;
            }
        }
        return true;
    }
};