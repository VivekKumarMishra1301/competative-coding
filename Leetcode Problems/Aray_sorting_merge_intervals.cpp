class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> hold;
        sort(intervals.begin(), intervals.end());
        vector<int> newInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > newInterval[1])
            {
                hold.push_back(newInterval);
                newInterval = intervals[i];
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        hold.push_back(newInterval);
        return hold;
    }
};