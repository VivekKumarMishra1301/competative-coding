class Solution {
public:
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first>p2.first){
            return false;
        }else if(p1.first<p2.first){
            return true;;
        }else{
            return p1.second<p2.second;
        }
        
    }
    
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int>hold;
        if(indexDifference==0&&valueDifference==0){
            hold.push_back(0);
            hold.push_back(0);
            return hold;
        }
        if(nums.size()==1&&(indexDifference!=0||valueDifference!=0)){
            hold.push_back(-1);
            hold.push_back(-1);
            return hold;
        }
        vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end(),cmp);
        // for(int i=0;i<p.size();i++){
        //     cout<<p[i].first<<" "<<p[i].second<<endl;
        // }
        int st=0;
        int en=0;
        while(en<nums.size()){
            bool flag=true;
            while(en<nums.size()&&abs(p[st].first-p[en].first)<valueDifference){
                en++;
                flag=false;
            }
            
            // cout<<en<<" ";
            
            for(int i=en;i<nums.size();i++){
                if(abs(p[st].second-p[i].second)>=indexDifference){
                    int f=min(p[st].second,p[i].second);
                    hold.push_back(f);
                    hold.push_back(max(p[st].second,p[i].second));
                    return hold;
                }
            }
            st++;
            if(flag){
                break;
            }
            
        }
        
        hold.push_back(-1);
        hold.push_back(-1);
        return hold;
    }
};