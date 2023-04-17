class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int ind = 0;
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int ncn = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    ncn++;
                }
            }
            if (ncn > cnt)
            {
                ind = i;
                cnt = ncn;
            }
        }

        vector<int> hold;
        hold.push_back(ind);
        hold.push_back(cnt);
        return hold;
    }
};