class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int st = 0;
        int en = 0;
        int leftsum = 0;
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        // int sumtomake=totalsum-x;
        int size = INT_MAX;
        if (totalsum == target)
        {
            return nums.size();
        }
        while (en < nums.size())
        {

            leftsum += nums[en];

            while (st < en && (leftsum - nums[st]) >= target)
            {
                leftsum -= nums[st];
                st++;
            }

            if (leftsum >= target)
            {
                size = min(size, en - st + 1);
            }
            en++;
        }
        // if(size==0){
        //     return -1;
        // }
        if (size == INT_MAX)
        {
            return 0;
        }
        return size;
    }
};