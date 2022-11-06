class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == nums[i - 1]) {
                nums[i - 1] = nums[i - 1] * 2;
                nums[i] = 0;
            }
        }

        vector<int>hold;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != 0) {
                hold.push_back(nums[i]);
            }
        }
        int count = nums.size() - hold.size();
        while (count--) {
            hold.push_back(0);
        }
        return hold;
    }
};