class Solution {
public:
    int averageValue(vector<int>& nums) {

        int count = 0;
        int sum = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] % 2 == 0 && nums[i] % 3 == 0) {
                sum = sum + nums[i];
                count++;
            }
        }
        if (sum == 0) {
            return 0;
        }
        double avg = sum / count;
        int favg = round(avg);
        return favg;
    }
};