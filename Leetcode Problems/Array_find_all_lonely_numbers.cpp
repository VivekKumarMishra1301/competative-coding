class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int>hold;
        if (nums.size() == 1) {
            hold.push_back(nums[0]);
            return hold;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0;i < nums.size() - 1;i++) {
            if (i == 0) {
                if (nums[i] != nums[i + 1] && abs(nums[i] - nums[i + 1]) != 1) {
                    hold.push_back(nums[i]);
                }
            }
            else {

                if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1] && abs(nums[i] - nums[i + 1]) != 1 && abs(nums[i] - nums[i - 1]) != 1) {
                    hold.push_back(nums[i]);
                }
            }

        }

        if (nums[nums.size() - 1] != nums[nums.size() - 2] && abs(nums[nums.size() - 1] - nums[nums.size() - 2]) != 1) {
            hold.push_back(nums[nums.size() - 1]);
        }

        return hold;
    }
};