class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, string> meraMap;
        for (auto i : s)
        {
            meraMap[i].push_back(i);
        }
        priority_queue<pair<int, string>> pq;
        for (auto i : meraMap)
        {
            pq.push({i.second.size(), i.second});
        }
        string hold = "";
        while (!pq.empty())
        {
            hold += pq.top().second;
            pq.pop();
        }
        return hold;
    }
};