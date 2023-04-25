class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, int> meraMap;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
        {
            pq.push(i);
            meraMap[i]++;
        }
    }

    int popSmallest()
    {
        int top = pq.top();
        meraMap.erase(top);
        pq.pop();
        return top;
    }

    void addBack(int num)
    {
        if (meraMap.find(num) == meraMap.end())
        {
            pq.push(num);
            meraMap[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */