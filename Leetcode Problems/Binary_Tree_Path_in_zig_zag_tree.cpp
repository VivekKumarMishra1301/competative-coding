class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        int lastlevel = 1;
        int currlevel = 0;
        while (currlevel < label)
        {
            currlevel += lastlevel;
            lastlevel *= 2;
        }
        lastlevel /= 2;
        vector<int> hold;
        while (label != 1)
        {
            hold.push_back(label);
            int complement = (3 * lastlevel - label - 1);
            int parent = complement / 2;
            label = parent;
            lastlevel /= 2;
        }
        hold.push_back(1);
        reverse(hold.begin(), hold.end());
        return hold;
    }
};