class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, vector<int>> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int sum = 0;
            while (num > 0)
            {
                sum += (num % 10);
                num /= 10;
            }

            meraMap[sum].push_back(nums[i]);
        }

        int maxSum = -1;
        for (auto i : meraMap)
        {
            vector<int> hold = i.second;
            if (hold.size() == 1)
            {
                continue;
            }
            sort(hold.begin(), hold.end());
            maxSum = max(maxSum, hold[hold.size() - 1] + hold[hold.size() - 2]);
        }
        return maxSum;
    }
};