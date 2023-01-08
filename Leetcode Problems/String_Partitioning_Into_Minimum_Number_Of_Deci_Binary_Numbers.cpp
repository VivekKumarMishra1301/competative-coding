class Solution
{
public:
    int minPartitions(string n)
    {
        char maxi = '0';
        for (int i = 0; i < n.size(); i++)
        {
            maxi = max(maxi, n[i]);
        }
        return maxi - '0';
    }
};