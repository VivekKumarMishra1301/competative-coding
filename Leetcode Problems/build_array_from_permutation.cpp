class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>hold;
        for (int i = 0;i < nums.size();i++) {
            hold.push_back(nums[nums[i]]);
        }
        return hold;
    }
};