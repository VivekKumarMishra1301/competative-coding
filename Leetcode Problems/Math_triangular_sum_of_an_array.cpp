class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        for (int i = 0;i < nums.size() - 1;i++) {
            for (int j = 1;j < nums.size() - i;j++) {
                int sum = (nums[j] + nums[j - 1]);
                nums[j - 1] = sum % 10;

            }
        }
        return nums[0];
    }
};