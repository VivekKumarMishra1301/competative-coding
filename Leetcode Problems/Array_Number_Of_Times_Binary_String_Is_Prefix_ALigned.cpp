class Solution
{
public:
    int numTimesAllBlue(vector<int> &flips)
    {
        int cnt = 0;
        int pref = 0;
        int indpref = 0;
        for (int i = 0; i < flips.size(); i++)
        {
            int curr = flips[i] - 1;
            pref += curr;
            indpref += i;
            if (pref - indpref == 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};