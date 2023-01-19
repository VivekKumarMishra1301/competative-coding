class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> meraMap;
        int i = 0;
        int count = 0;
        int sum = 0;
        while (i < nums.size())
        {
            sum += nums[i];
            if (sum % k == 0)
            {
                count++;
            }
            int x = sum % k;
            if (x < 0)
            {
                x = x + k;
            }

            if (meraMap.find(x) != meraMap.end())
            {
                count += meraMap[x];
                // meraMap[sum%k]++;
                // count++;
            }

            meraMap[x] += 1;

            i++;
        }
        // for(auto k:meraMap){
        //     cout<<k.first<<k.second<<" ";
        // }
        return count;
    }
};