class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());

        for (int i = 0; i < points.size(); i++)
        {
            cout << points[i][0] << " " << points[i][1] << endl;
        }

        int count = 1;
        int p1 = points[0][0];
        int p2 = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] >= p1 && points[i][0] <= p2)
            {
                p1 = max(p1, points[i][0]);
                p2 = min(p2, points[i][1]);
            }
            else
            {
                count++;
                p1 = points[i][0];
                p2 = points[i][1];
            }
        }
        return count;
    }
};