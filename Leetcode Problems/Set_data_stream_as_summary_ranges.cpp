class SummaryRanges
{
public:
    // unordered_map<int,int>meraMap;
    set<int> meraSet;
    SummaryRanges()
    {
    }

    void addNum(int value)
    {
        // meraMap[value]++;
        meraSet.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> hold;
        int first = -1;
        int sec = -1;
        int count = -1;
        for (auto i : meraSet)
        {
            if (first == -1)
            {
                first = i;
                sec = i;
                count = i + 1;
            }
            else if (i == (count))
            {
                sec = count;
                count++;
                continue;
            }
            else
            {
                hold.push_back({first, sec});
                first = i;
                sec = i;
                count = i + 1;
            }
        }
        if (first != -1)
        {
            hold.push_back({first, sec});
        }
        return hold;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */