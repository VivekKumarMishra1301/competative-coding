class Solution
{
public:
    int minpath(int ind, int r, vector<vector<int>> &triangle, vector<vector<int>> &memo)
    {
        if (r == triangle.size())
        {
            return 0;
        }
        if (memo[r][ind] != -1)
        {
            return memo[r][ind];
        }

        int a = triangle[r][ind] + minpath(ind, r + 1, triangle, memo);
        int b = triangle[r][ind] + minpath(ind + 1, r + 1, triangle, memo);
        return memo[r][ind] = min(a, b);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> memo(triangle.size() + 1, vector<int>(triangle[triangle.size() - 1].size() + 1, -1));
        return minpath(0, 0, triangle, memo);
    }
};