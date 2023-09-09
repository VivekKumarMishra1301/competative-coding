class Solution
{
public:
    void make(int ind, int k, int n, vector<vector<int>> &hold, vector<int> &temp)
    {
        if (k == 0)
        {
            if (n == 0)
                hold.push_back(temp);
            return;
        }
        if (n == 0)
        {
            return;
        }
        if (ind > 9)
        {
            return;
        }

        for (int i = ind; i <= 9; i++)
        {
            if (i <= n)
            {
                temp.push_back(i);
                make(i + 1, k - 1, n - i, hold, temp);
                temp.pop_back();
            }
            else
            {
                make(i + 1, k, n, hold, temp);
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> hold;
        vector<int> temp;
        make(1, k, n, hold, temp);
        return hold;
    }
};