class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        for (int i = 0; i < capacity.size(); i++)
        {
            capacity[i] = capacity[i] - rocks[i];
        }

        sort(capacity.begin(), capacity.end());

        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] != 0)
            {
                if (additionalRocks >= capacity[i])
                {

                    additionalRocks -= capacity[i];
                    capacity[i] = 0;
                }
                else
                {
                    capacity[i] = capacity[i] - additionalRocks;
                    additionalRocks = 0;
                }
            }
            if (additionalRocks == 0)
            {
                break;
            }
        }
        int count = 0;
        for (int i = 0; i < capacity.size(); i++)
        {
            if (capacity[i] == 0)
            {
                count++;
            }
        }
        return count;
    }
};