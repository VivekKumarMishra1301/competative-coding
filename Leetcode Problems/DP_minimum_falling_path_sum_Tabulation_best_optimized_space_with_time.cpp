class Solution
{
public:
    int minpath(vector<vector<int>> &matrix, int n, int m)
    {
        vector<int> prev(n);
        vector<int> curr(m);
        for (int i = 0; i < m; i++)
        {
            prev[i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int vert = matrix[i][j] + prev[j];
                int leftdia = matrix[i][j];
                if (j - 1 >= 0)
                {
                    leftdia += prev[j - 1];
                }
                else
                {
                    leftdia = 1e9;
                }

                int rightdia = matrix[i][j];
                if (j + 1 < m)
                {
                    rightdia += prev[j + 1];
                }
                else
                {
                    rightdia = 1e9;
                }

                curr[j] = min(vert, min(leftdia, rightdia));
            }
            prev = curr;
        }
        int mini = prev[0];
        for (int i = 1; i < m; i++)
        {
            mini = min(mini, prev[i]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        return minpath(matrix, matrix.size(), matrix[0].size());
    }
};