class Solution
{
public:
    long long beautifulSubarrays(vector<int> &nums)
    {
        // if(nums.size()==1&&nums[0]==0){
        //     return 1;
        // }
        long long hold = 0;
        unordered_map<int, int> meraMap;
        // meraMap[0]++;
        // int x=nums[0];
        int x = 0;
        meraMap[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            x = x ^ nums[i];
            // if(meraMap.find(x)!=meraMap.end()){
            hold += meraMap[x];
            meraMap[x]++;
            // }
        }

        // for(auto i:meraMap){
        //     if(i.second>1){
        //         hold+=i.second;
        //     }
        // }
        return hold;
    }
};