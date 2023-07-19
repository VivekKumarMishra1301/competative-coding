class Solution
{
public:
    //      static  bool sortcol( const vector<int>& v1,
    //                const vector<int>& v2 ) {
    //     return v1[1] > v2[1];
    // }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int cnt = -1;
        vector<int> p = intervals[0];
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] < p[1] && intervals[i][1] <= p[1])
            {
                cnt++;
                p = intervals[i];
            }
            else if (intervals[i][0] < p[1] && intervals[i][1] > p[1])
            {
                cnt++;
            }
            else
            {
                p = intervals[i];
            }
        }
        return cnt;
    }
};