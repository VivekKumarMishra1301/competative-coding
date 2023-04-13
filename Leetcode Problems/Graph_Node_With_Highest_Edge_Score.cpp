class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        map<int, long> meraMap;
        for (int i = 0; i < edges.size(); i++)
        {
            if (meraMap.find(edges[i]) == meraMap.end())
            {
                meraMap[edges[i]] = 0;
                meraMap[edges[i]] = meraMap[edges[i]] + long(i);
            }
            else
            {
                meraMap[edges[i]] = meraMap[edges[i]] + long(i);
            }
        }
        int hold = 0;
        long mfrq = -1;
        for (auto i : meraMap)
        {
            if (i.second > mfrq)
            {
                mfrq = i.second;
                hold = i.first;
            }
        }
        return hold;
    }
};
















bool is(int san)
{
    
                if (san <= 1)
                    return false;

  if (san == 2 || san == 3)
        return true;
                    
                    if (san % 2 == 0 || san % 3 == 0)
                        return false;
     
    
            for (int i = 5; i <= sqrt(san); i = i + 6)
        if (san % i == 0 || san % (i + 2) == 0)
            return false;
 
    return true;
}