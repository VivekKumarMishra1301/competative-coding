class TimeMap
{
public:
    map<string, map<int, string, greater<int>>> meraMap;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        meraMap[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (meraMap.find(key) == meraMap.end())
        {
            return "";
        }
        auto itr = meraMap[key].lower_bound(timestamp);
        if (itr == meraMap[key].end())
        {
            return "";
        }
        return itr->second;
    }
};

/**
 * @brief 
 * 
 */
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */