class FrequencyTracker
{
public:
    map<int, int> meraMap;
    map<int, int> freq;
    int maxfreq = 0;
    priority_queue<pair<int, int>> p;
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        if (freq[meraMap[number]] > 0)
        {
            freq[meraMap[number]]--;
        }
        ++meraMap[number];
        freq[meraMap[number]]++;
    }
    void deleteOne(int number)
    {
        if (meraMap[number] > 0)
        {
            freq[meraMap[number]]--;
            meraMap[number]--;
            freq[meraMap[number]]++;
        }
    }
    bool hasFrequency(int frequency)
    {
        return freq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */