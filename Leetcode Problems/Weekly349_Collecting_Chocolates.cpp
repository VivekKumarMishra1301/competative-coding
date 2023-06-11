class Solution
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        long long hold = LONG_MAX;

        // for(int i=0;i<nums.size();i++){
        //     long long su=nums[i];
        //     long long marg=0;
        //     long long s=x;
        //     long long prevs=LONG_MAX;
        //     for(int j=(i+1)%nums.size();j<nums.size();j=(j+1)%nums.size()){
        //         if(j==i){
        //             break;
        //         }
        //         marg=abs(i-j)*s;
        //         long long d=(nums.size()-i+(j))*s;
        //         marg=min(marg,d);
        //         if((marg+nums[j])<nums[i]&&(marg+nums[j])<prevs){
        //             prevs=marg+nums[j];
        //         }
        //     }
        //     if(prevs>nums[i]){
        //         hold+=su;
        //     }else{
        //         hold+=prevs;
        //     }
        //     cout<<hold<<" ";
        // }

        vector<int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
        }
        vector<long> costarr(nums.size(), LONG_MAX);

        for (int i = 0; i < nums.size(); i++)
        {
            long long s = 0;
            long long k = x;
            long long sm = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (costarr[j] > temp[i + j])
                    costarr[j] = temp[i + j];
                s += costarr[j];
            }

            s += (long)i * k;
            hold = min(hold, s);
        }

        return hold;
    }
};