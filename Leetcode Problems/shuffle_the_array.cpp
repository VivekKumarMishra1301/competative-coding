class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>hold;

        for (int i = 0;i < n;i++) {
            hold.push_back(nums[i]);
            hold.push_back(nums[i + n]);
        }
        return hold;
    }
};