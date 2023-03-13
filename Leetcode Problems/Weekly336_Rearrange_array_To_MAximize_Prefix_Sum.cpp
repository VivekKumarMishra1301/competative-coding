class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        int hold = 0;
        priority_queue<int> pq;
        for (auto i : nums)
        {
            pq.push(i);
        }
        vector<long long> ar;
        long long s = 0;
        while (!pq.empty())
        {
            s += pq.top();
            ar.push_back(s);
            pq.pop();
        }

        for (auto i : ar)
        {
            if (i > 0)
            {
                hold++;
            }
        }
        return hold;
    }
};