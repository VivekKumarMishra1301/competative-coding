class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>get;
        vector<int>store(3);
        for(int i=0;i<nums.size()-2;i++){
            int st=i+1,end=nums.size()-1,sum=0-nums[i];
            if(i==0||(i>0&&nums[i]!=nums[i-1])){
                while(st<end){
                    if((nums[st]+nums[end])==sum){
                        store[0]=nums[i];
                        store[1]=nums[st];
                        store[2]=nums[end];
                        get.push_back(store);
                        while(st<end&&nums[st]==nums[st+1]){
                            st++;
                        }
                        while(st<end&&nums[end]==nums[end-1]){
                            end--;
                        }
                        
                        st++;
                        end--;
                    }else if((nums[st]+nums[end])<sum){
                        st++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return get;
    }
};