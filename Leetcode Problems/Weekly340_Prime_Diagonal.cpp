class Solution
{
public:
    bool is(int san)
    {

        if (san <= 1)
            return false;

        if (san == 2 || san == 3)
            return true;

        if (san % 2 == 0 || san % 3 == 0)
            return false;

        for (int i = 5; i <= sqrt(san); i = i + 6)
            if (san % i == 0 || san % (i + 2) == 0)
                return false;

        return true;
    }

    int diagonalPrime(vector<vector<int>> &nums)
    {
        vector<int> diag;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[0].size(); j++)
            {
                if (i == j || (i + j) == nums.size() - 1)
                {
                    diag.push_back(nums[i][j]);
                }
            }
        }

        sort(diag.begin(), diag.end());
        // bool san[diag[diag.size()-1]+1];
        for (int i = diag.size() - 1; i >= 0; i--)
        {
            if (is(diag[i]))
            {
                return diag[i];
            }
        }
        return 0;
    }
};