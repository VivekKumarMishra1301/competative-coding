class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int del = 0;
        int n = strs[0].size();
        for (int i = 0; i < n; i++)
        {
            char take = strs[0][i];
            bool flag = false;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] < take)
                {
                    flag = true;
                    break;
                }
                else
                {
                    take = strs[j][i];
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