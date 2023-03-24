class Solution
{
public:
    class cmp
    {
    public:
        bool operator()(const pair<int, string> &p1, const pair<int, string> &p2)
        {
            if (p1.first == p2.first)
                return p1.second < p2.second;

            return p1.first > p2.first;
        }
    };

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> meraMap;
        for (auto i : words)
        {
            meraMap[i]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto i : meraMap)
        {
            pq.push(make_pair(i.second, i.first));
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<string> hold;
        while (!pq.empty())
        {
            hold.push_back(pq.top().second);
            pq.pop();
        }
        reverse(hold.begin(), hold.end());
        return hold;
    }
};