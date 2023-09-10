class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> pref(boxes.size(), 0);
        vector<int> suf(boxes.size(), 0);
        int s = 0;
        int m = 0;
        for (int i = 1; i < boxes.size(); i++)
        {
            if (boxes[i - 1] == '1')
            {
                m++;
            }
            s = s + m;
            pref[i] = s;
        }

        s = 0;
        m = 0;
        for (int i = boxes.size() - 1; i >= 0; i--)
        {
            if (boxes[i + 1] == '1')
            {
                m++;
            }
            s = s + m;
            suf[i] = s;
        }
        vector<int> hold(boxes.size(), 0);
        for (int i = 0; i < hold.size(); i++)
        {
            hold[i] = pref[i] + suf[i];
        }
        return hold;
    }
};