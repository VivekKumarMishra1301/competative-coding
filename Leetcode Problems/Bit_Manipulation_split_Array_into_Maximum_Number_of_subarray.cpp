class Solution
{
public:
    //     pair<int,int>makeSub(int st,vector<int>&nums,int en){
    //         if(st==en){
    //             return {1,nums[st]};
    //         }

    //         int part=-1;
    //         // for(int i=st+1;i<=en;i++){
    //         //     if(nums[i]>=nums[i-1]){
    //         //         part=i;
    //         //         break;
    //         //     }
    //         // }

    //         int mini=nums[st];
    //         for(int i=st+1;i<=en;i++){
    //             int nmini=mini&nums[i];
    //             // mini=mini&nums[i];
    //             if(nmini<mini){
    //                 mini=nmini;
    //             }else{
    //                 part=i;
    //                 break;
    //             }
    //         }
    //         if(part==-1){
    //             return {1,mini};
    //         }

    //         pair<int,int>first=makeSub(st,nums,part-1);
    //         pair<int,int>sec=makeSub(part,nums,en);
    //         cout<<st<<","<<en<<": first"<<first.first<<" "<<first.second<<" second"<<sec.first<<" "<<sec.second<<endl;
    //         if(first.second==0&&sec.second==0){
    //             return {first.first+sec.first,0};
    //         }else{
    //             return{max(first.first,sec.first),first.second&sec.second};
    //         }

    //     }

    int maxSubarrays(vector<int> &nums)
    {

        int bitm = nums[0];

        for (auto i : nums)
        {
            bitm = bitm & i;
        }
        if (bitm != 0)
        {
            return 1;
        }
        int nu = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            nu = nu & nums[i];
            if (nu == 0)
            {
                cnt++;
                nu = INT_MAX;
            }
        }
        return cnt;
    }
};