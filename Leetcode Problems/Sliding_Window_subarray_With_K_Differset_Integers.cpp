class Solution
{
public:
    int atmost(vector<int> &nums, int k)
    {
        map<int, int> meraMap;
        int hold = 0;
        int st = 0;
        int en = 0;
        while (en < nums.size())
        {
            meraMap[nums[en]]++;
            while (meraMap.size() > k)
            {

                auto it = meraMap.find(nums[st]);
                it->second--;
                if (it->second == 0)
                {
                    meraMap.erase(it);
                }
                st++;
            }
            hold += (en - st + 1);
            en++;
        }
        return hold;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        return atmost(nums, k) - atmost(nums, k - 1);

        // while(en<nums.size()){
        //     meraMap[nums[en]]++;
        //     if(meraMap.size()==k){
        //         hold++;
        //     }else if(meraMap.size()>k){
        //         meraMap.erase(nums[en]);
        //         bool flag=false;
        //         while(st<en&&meraMap.size()==k){
        //             if(flag)
        //             hold++;
        //             flag=true;
        //             meraMap[nums[st]]--;
        //             if(meraMap[nums[st]]==0){
        //                 meraMap.erase(nums[st]);
        //             }
        //             st++;
        //         }
        //         meraMap[nums[en]]++;
        //         if(meraMap.size()==k){
        //             hold++;
        //         }
        //     }
        //     en++;
        // }
        // // if(meraMap.size()==k){
        // //     hold++;
        // // }
        // return hold;
    }
};