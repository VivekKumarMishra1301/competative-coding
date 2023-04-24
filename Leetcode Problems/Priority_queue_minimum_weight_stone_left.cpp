class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto i : stones)
        {
            pq.push(i);
        }

        int rmn = 0;
        while (!pq.empty())
        {
            int t1 = pq.top();
            pq.pop();
            int t2 = 0;
            if (!pq.empty())
            {
                t2 = pq.top();
                pq.pop();
                if (t1 != t2)
                {
                    pq.push(t1 - t2);
                }
            }
            else
            {
                return t1;
            }
        }
        return rmn;
    }
};