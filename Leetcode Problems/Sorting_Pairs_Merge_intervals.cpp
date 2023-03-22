class Solution
{
public:
    static bool sortcol(const vector<int> &v1,
                        const vector<int> &v2)
    {
        return v1[1] > v2[1];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> hold;
        sort(intervals.begin(), intervals.end(), sortcol);
        int st = intervals[0][0];
        int en = intervals[0][1];
        cout << st << " " << en << endl;
        for (int i = 1; i < intervals.size(); i++)
        {
            int fs = intervals[i][0];
            int fe = intervals[i][1];
            cout << st << " " << en << endl;
            if (fs >= st && fs <= en)
            {
                continue;
            }
            else if (fe >= st && fe <= en)
            {
                st = fs;
            }
            else
            {
                hold.push_back({st, en});
                en = fe;
                st = fs;
            }
        }
        hold.push_back({st, en});

        return hold;
    }
};