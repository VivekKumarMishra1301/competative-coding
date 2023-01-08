class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int size = points.size();
        if (size <= 2)
        {
            return size;
        }

        int maxi = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int total = 2;
                for (int k = 0; k < size; k++)
                {
                    if (k != i && k != j)
                    {

                        if ((points[j][1] - points[i][1]) * (points[k][0] - points[i][0]) == (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]))
                        {
                            total++;
                        }
                    }
                }
                maxi = max(maxi, total);
            }
        }

        return maxi;
    }
};