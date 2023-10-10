class Solution {
public:
    int minOperations(vector<int>& nums) {
        int hold=nums.size()-1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        auto it=unique(nums.begin(),nums.end());
        nums.erase(it,nums.end());
        
        for(int i=0;i<nums.size();i++){
            int st=nums[i];
            int en=st+n-1;
            int k=upper_bound(nums.begin()+i,nums.end(),en)-nums.begin();
            hold=min(hold,n-k+i);
        }
        return hold;
    }
};