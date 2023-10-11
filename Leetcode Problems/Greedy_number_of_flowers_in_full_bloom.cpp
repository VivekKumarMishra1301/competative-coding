class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)     {
        vector<pair<int,int>>pr;
        for(int i=0;i<people.size();i++){
            pr.push_back({people[i],i});
        }
        sort(flowers.begin(),flowers.end());
        sort(pr.begin(),pr.end());
        int ind=0;
        vector<int>hold(people.size());
        multiset<int>ms;
        for(int i=0;i<pr.size();i++){
            while(ind<flowers.size()&&pr[i].first>=flowers[ind][0]){
                ms.insert(flowers[ind][1]);
                ind++;
            }
            
            while(ms.size()&&(*(ms.begin())<pr[i].first)){
                ms.erase(ms.begin());
            }
            hold[pr[i].second]=ms.size();
            
        }
        return hold;
    }
};