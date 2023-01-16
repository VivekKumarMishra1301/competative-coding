class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> hold;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval[0] > intervals[i][1])
            { // not in range
                hold.push_back(intervals[i]);
            }
            else if (newInterval[1] < intervals[i][0])
            { // lesser than the current range
                hold.push_back(newInterval);
                newInterval = intervals[i];
            }
            else
            {
                // creating new Interval
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        hold.push_back(newInterval);
        return hold;
    }
};