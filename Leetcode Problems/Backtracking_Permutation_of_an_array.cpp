class Solution {
public:
    
    void permutation(vector<int>& nums,int ind,vector<vector<int>>&hold){
        if(ind==nums.size()-1){
            hold.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            permutation(nums,ind+1,hold);
            swap(nums[ind],nums[i]);
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>hold;
        permutation(nums,0,hold);
        return hold;
    }
};