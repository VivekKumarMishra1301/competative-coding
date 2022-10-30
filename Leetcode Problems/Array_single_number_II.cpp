class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size();i++) {
            if (i < nums.size() - 1 && nums[i] != nums[i + 1]) {
                return nums[i];
            }
            else if (i == nums.size() - 1) {
                return nums[nums.size() - 1];
            }
            if (i < nums.size() - 2)
                i += 2;
        }
        return nums[0];
    }
};