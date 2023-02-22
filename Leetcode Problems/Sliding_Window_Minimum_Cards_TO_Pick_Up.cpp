class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int st = 0;
        int en = 0;
        int size = INT_MAX;
        unordered_map<int, vector<int>> meraMap;
        while (en < cards.size())
        {
            if (meraMap.find(cards[en]) == meraMap.end())
            {
                meraMap[cards[en]].push_back(en);
                en++;
            }
            else
            {
                vector<int> temp = meraMap[cards[en]];
                int in = temp[temp.size() - 1];
                size = min(size, en - in + 1);
                meraMap[cards[en]].push_back(en);
                en++;
            }
        }
        if (size == INT_MAX)
        {
            return -1;
        }
        return size;
    }
};