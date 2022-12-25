class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        int pos = 0;
        int prev = 0;

        for (int i = 0; i < forts.size(); i++)
        {
            if (forts[prev] == 1 && forts[i] == -1)
            {
                pos = max(pos, i - prev - 1);

                prev = i;
            }
            else if (forts[prev] == -1 && forts[i] == 1)
            {
                pos = max(pos, i - prev - 1);
                prev = i;
            }
            else if (forts[prev] == 1 && forts[i] == 1)
            {
                prev = i;
            }
            else if (forts[prev] == -1 && forts[i] == -1)
            {
                prev = i;
            }
            else if (forts[prev] == 0 && (forts[i] == 1 || forts[i] == -1))
            {
                prev = i;
            }
        }

        return pos;
    }
};