class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + n % 10;
            n = n / 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        vector<int>hold = nums;
        for (int i = 0;i < nums.size();i++) {
            hold.push_back(reverse(nums[i]));
        }

        sort(hold.begin(), hold.end());
        int count = 0;
        for (int i = 1;i < hold.size();i++) {
            if (hold[i] != hold[i - 1]) {
                count++;
            }
        }
        return count + 1;
    }
};