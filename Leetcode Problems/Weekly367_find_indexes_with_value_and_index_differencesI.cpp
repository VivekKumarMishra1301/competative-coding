class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int>hold;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(abs(i - j) >= indexDifference&&abs(nums[i] - nums[j]) >= valueDifference){
                    hold.push_back(i);
                    hold.push_back(j);
                    return hold;
                }
            }
        }
        hold.push_back(-1);
        hold.push_back(-1);
        return hold;
    }
};