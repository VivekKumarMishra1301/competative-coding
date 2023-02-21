class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int st = 0;
        int en = 0;
        int leftsum = 0;
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int sumtomake = totalsum - x;
        int size = 0;
        if (totalsum == x)
        {
            return nums.size();
        }
        while (en < nums.size())
        {

            leftsum += nums[en];

            while (st < en && leftsum > sumtomake)
            {
                leftsum -= nums[st];
                st++;
            }

            if (leftsum == sumtomake)
            {
                size = max(size, en - st + 1);
            }
            en++;
        }
        if (size == 0)
        {
            return -1;
        }
        return nums.size() - size;
    }
};