class Solution {
public:


    int subarraySum(vector<int>& nums, int k) {
        int currentSum = 0;
        int count = 0;
        int i = 0;
        if (nums.size() == 0) {
            return 0;
        }

        unordered_map<int, int>meraMap;
        while (i < nums.size()) {
            currentSum += nums[i];
            if (currentSum == k) {
                count++;
            }

            if (meraMap.find(currentSum - k) != meraMap.end()) {
                count += meraMap[currentSum - k];
            }
            meraMap[currentSum] += 1;
            i++;
        }
        return count;

    }
};