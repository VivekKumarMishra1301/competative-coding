class Solution
{
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2)
    {
        string starttime1 = event1[0];
        string starttime2 = event2[0];
        string endtime1 = event1[1];
        string endtime2 = event2[1];
        string st1 = "";
        string st2 = "";
        string end1 = "";
        string end2 = "";
        for (int i = 0; i < 5; i++)
        {
            if (i != 2)
            {
                st1 = st1 + starttime1[i];
                st2 = st2 + starttime2[i];
                end1 = end1 + endtime1[i];
                end2 = end2 + endtime2[i];
            }
        }
        bool range = true;
        int s1 = 0;
        int s2 = 0;
        int e1 = 0;
        int e2 = 0;
        int r = 1;
        for (int i = 0; i < 4; i++)
        {
            s1 = s1 * r + st1[i] - 48;
            s2 = s2 * r + st2[i] - 48;
            e1 = e1 * r + end1[i] - 48;
            e2 = e2 * r + end2[i] - 48;
            r = r * 10;
        }
        if (s2 > s1)
        {
            if (e1 < s2)
            {
                return false;
            }
        }
        else
        {
            if (s1 > e2)
            {
                return false;
            }
        }
        return true;
    }
};