class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> prev;
        // vector<int>curr;
        prev.push_back((double)(poured));
        // query_row--;
        vector<double> hold;
        hold.push_back(poured);
        for (int j = 0; j < query_row; j++)
        {
            vector<double> curr(prev.size() + 1, 0);
            vector<double> n(prev.size() + 1, 0);
            bool flag = true;
            for (int i = 0; i < curr.size(); i++)
            {
                double total = 0;
                if (i - 1 >= 0 && prev[i - 1] > 1)
                {
                    total += (((double)prev[i - 1] - 1) / 2);
                }
                if (i < prev.size() && prev[i] > 1)
                {
                    total += (((double)prev[i] - 1) / 2);
                }
                n[i] = total;

                curr[i] = total;
                if (curr[i] != 0)
                {
                    flag = false;
                }
                // cout<<curr[i]<<" ";
            }
            if (flag)
            {
                return (double)0;
            }
            prev = curr;
            hold = curr;
            // cout<<endl;
            // cout<<j<<" ";
        }
        if (hold[query_glass] > 1)
        {
            return 1;
        }
        return hold[query_glass];
    }
};