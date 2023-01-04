class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int del = 0;
        int n = strs[0].size();
        for (int j = 0; j < n; j++)
        {
            char take = strs[0][j];
            bool flag = false;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][j] < take)
                {
                    flag = true;
                    break;
                }
                else
                {
                    take = strs[j][j];
                }
            }
            if (flag)
            {
                del++;
            }
        }
        return del;
    }
};
