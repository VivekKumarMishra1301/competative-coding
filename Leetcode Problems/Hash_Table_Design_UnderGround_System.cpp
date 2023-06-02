class st
{
public:
    string src;
    string dst;
    int in;
    int out;
};

class UndergroundSystem
{
public:
    // map<int,map<string,vector<int>>>m1;
    // map<int,map<string,vector<int>>>m2;
    map<pair<string, string>, vector<int>> dura;
    map<int, st> yatra;
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        // m1[id][stationName].push_back(t);

        st k;
        k.src = stationName;
        k.in = t;
        yatra[id] = k;
    }

    void checkOut(int id, string stationName, int t)
    {
        // m2[id][stationName].push_back(t);

        st d = yatra[id];
        d.out = t;
        d.dst = stationName;
        dura[{d.src, d.dst}].push_back(d.out - d.in);
    }

    double getAverageTime(string startStation, string endStation)
    {
        //         int cnt=0;
        //         for(auto it:m1){
        //             auto i=m1.find(startStation);
        //             if(i==m1.end()){
        //                 continue;
        //             }

        //             for( )

        auto it = dura.find({startStation, endStation});
        if (it == dura.end())
        {
            return (double)0;
        }

        double sz = it->second.size();
        return accumulate(it->second.begin(), it->second.end(), 0) / sz;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */