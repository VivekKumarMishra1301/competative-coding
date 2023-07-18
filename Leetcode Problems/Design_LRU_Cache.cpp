class LRUCache
{
public:
    map<int, pair<int, int>> lru;
    map<int, int> cnt;
    int cap;
    int entry = 0;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (lru.find(key) != lru.end())
        {

            int pos = lru[key].first;
            cnt.erase(pos);
            lru[key].first = entry;
            cnt[entry++] = key;

            // cout<<cnt[entry-1]<<" "<<endl;
            // for(auto i:cnt){
            //     cout<<i.first<<":"<<i.second<<endl;
            // }
            // cout<<"get khatam"<<endl;

            return lru[key].second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (lru.find(key) != lru.end())
        {
            int pos = lru[key].first;
            cnt.erase(pos);
            lru[key].first = entry;
            lru[key].second = value;
            cnt[entry++] = key;
        }
        else
        {

            if (lru.size() == cap)
            {
                int val = cnt.begin()->second;
                cnt.erase(cnt.begin());
                lru.erase(val);
                // cout<<val<<" ";
                // for(auto i:cnt){
                //     cout<<i.first<<":"<<i.second<<endl;
                // }
                // cout<<"put khatam"<<endl;
            }
            lru.insert({key, {entry, value}});
            cnt[entry++] = key;
        }

        // if(lru.find(key)==lru.end()){
        // }else{
        //     int pos=lru[key].first;
        //     cnt.erase(pos);
        //     lru[key].first=entry;
        //     lru[key].second=value;
        //     cnt[entry++]=key;
        // }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */