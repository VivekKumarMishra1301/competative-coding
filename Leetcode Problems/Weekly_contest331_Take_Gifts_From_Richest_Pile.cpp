class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;
        for (auto i : gifts)
        {
            pq.push(i);
        }

        while (k--)
        {
            int top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top)));
        }
        long long hold = 0;

        while (!pq.empty())
        {
            hold += pq.top();
            pq.pop();
        }
        return hold;
    }
};