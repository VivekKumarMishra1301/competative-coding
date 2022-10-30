class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;
        for (int i = 0;i < nums.size();i++) {
            int count = 0;
            for (int j = i;j < nums.size();j++) {
                if (nums[j] > nums[i]) {
                    break;
                }
                count++;
            }
            if (count < 2) {
                nums[k++] = nums[i];
            }
            else {
                nums[k++] = nums[i];
                nums[k++] = nums[i];
            }
            i += count;
            i--;
        }
        return k;
    }
};