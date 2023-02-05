class Solution {
public:
    
    
    int find(vector<int>&arr,int ind,vector<int>&dp,int k){
	    if(ind<0){
	        return 0;
	    }
        if(k==0){
            return arr[ind];
        }
	    if(dp[ind]!=-1){
	        return dp[ind];
	    }
	    return dp[ind]=max(arr[ind]+find(arr,ind-2,dp,k-1),find(arr,ind-1,dp,k));
	    
	}
    
    
    int minCapability(vector<int>& nums, int k) {
        if(k==nums.size()){
            return accumulate(nums.begin(),nums.end(),0);
        }
        
        vector<int>dp(nums.size(),-1);
	    return find(nums,nums.size()-1,dp,k);
        
        
    }
};