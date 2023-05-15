class Solution
{
public:
    int sumOfPower(vector<int> &nums)
    {
        //         priority_queue<int>pq;
        //         map<int,int>meraMap;
        //         for(auto i:nums){
        //             pq.push(i);
        //             meraMap[i]++;
        //         }
        int mod = 1000000007;
        //         int hold=0;
        //         while(!pq.empty()){
        //             int tp=pq.top();
        //             pq.pop();

        //             for(auto i :meraMap){
        //             hold=(hold+(i.second*(((tp*tp)%mod)*i.first)%mod)%mod)%mod;
        //                 meraMap.erase(tp);

        //             }

        //         }
        //         return hold;
        sort(nums.begin(), nums.end());
        long hold = ((((long)nums[0] * (long)nums[0]) % mod) * nums[0]) % mod;
        long fact = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            fact = ((fact * 2) % mod) - nums[i - 1] + nums[i];
            hold = (hold + ((((long)nums[i] * (long)nums[i]) % mod) * fact) % mod) % mod;
        }

        return hold;
    }
};