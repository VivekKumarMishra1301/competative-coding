class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        priority_queue<int> pq;
        map<int, int> meraMap;
        for (auto i : arr)
        {
            meraMap[i]++;
        }

        for (auto i : meraMap)
        {
            pq.push(i.second);
        }

        int st = 0;
        int s = 0;
        while (!pq.empty())
        {
            int tp = pq.top();
            pq.pop();
            s += tp;
            st++;
            if (s >= arr.size() / 2)
            {
                return st;
            }
        }
        return st;
    }
};