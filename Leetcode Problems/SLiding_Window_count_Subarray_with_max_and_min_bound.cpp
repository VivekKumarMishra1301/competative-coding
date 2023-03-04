class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long hold = 0;
        //         int st=0;
        //         int en=0;
        //         int maxi=nums[0];
        //         int mini=nums[0];
        //         unordered_map<int,int>meraMap;
        //         bool flag=true;
        //         while(en<nums.size()){
        //             if(nums[en]<=maxK&&nums[en]>=minK){
        //                 if(nums[en]<mini){
        //                     mini=nums[en];
        //                 }
        //                 if(nums[en]>maxi){
        //                     maxi=nums[en];
        //                 }
        //             meraMap[nums[en]]++;

        //                 if(maxi==maxK&&mini==minK){
        //                     if(meraMap.size()==1&&flag){
        //                         int n=en-st+1;
        //                         hold+=(n*(n+1))/2;
        //                         flag=false;
        //                     }else if(meraMap.size()==1){
        //                         int n=en-st+1;

        //                         hold=(n*(n+1))/2;
        //                         cout<<n<<hold<<en<<" ";
        //                         flag=false;
        //                     }else{
        //                     hold++;

        //                     }
        //                 }
        //                 // en++;

        //             }else{
        //                 while(meraMap.size()!=0){
        //                     flag=true;
        //                     meraMap[nums[st]]--;
        //                     if(meraMap[nums[st]]==0){
        //                         meraMap.erase(nums[st]);
        //                     }
        //                     if(meraMap.find(maxK)!=meraMap.end()&&meraMap.find(minK)!=meraMap.end()){
        //                     // cout<<meraMap.size()<<endl;
        //                         hold++;
        //                     }
        //                     st++;
        //                 }
        //                 st++;
        //                 en++;
        //                 maxi=nums[en];
        //                 mini=nums[en];
        //                 continue;
        //             }
        //             en++;
        //             // for(auto i:meraMap){
        //             //     cout<<i.first<<" ";
        //             // }
        //             // cout<<endl;
        //         }
        vector<int> mini, maxi;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == minK)
            {
                mini.push_back(i);
            }
            if (nums[i] == maxK)
            {
                maxi.push_back(i);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                continue;
            }
            int l = i;
            while (i < nums.size() && nums[i] >= minK && nums[i] <= maxK)
            {
                i++;
            }
            i--;
            int last = l - 1;
            for (int j = l; j <= i; j++)
            {
                if (nums[j] == minK)
                {
                    int next = lower_bound(maxi.begin(), maxi.end(), j) - maxi.begin();
                    long long cnt1 = j - last;
                    if (next == maxi.size())
                    {
                        continue;
                    }
                    long long cnt2 = i - maxi[next] + 1;
                    if (cnt2 > 0)
                    {
                        hold += (cnt1 * cnt2);
                        last = j;
                    }
                }
                else if (nums[j] == maxK)
                {
                    int next = lower_bound(mini.begin(), mini.end(), j) - mini.begin();
                    long long cnt1 = j - last;
                    if (next == mini.size())
                    {
                        continue;
                    }
                    long long cnt2 = i - mini[next] + 1;
                    if (cnt2 > 0)
                    {
                        hold += (cnt1 * cnt2);
                        last = j;
                    }
                }
            }
        }

        return hold;
    }
};