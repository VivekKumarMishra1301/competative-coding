class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return false;
        }
        unordered_map<int, vector<int>> meraMap;
        for (int i = 0; i < nums.size(); i++)
        {
            meraMap[nums[i]].push_back(i);
        }

        for (auto i : meraMap)
        {
            vector<int> hold = i.second;
            int st = 0;
            int end = hold.size() - 1;
            // while(st<end){
            //     if(abs(hold[st]-hold[end])==k){
            //         return true;
            //     }else if((abs(hold[st]-hold[end])<k)){
            //         st++;
            //     }else{
            //         end--;
            //     }
            // }
            for (int i = 0; i < end; i++)
            {
                for (int j = i + 1; j <= end; j++)
                {
                    if (abs(hold[i] - hold[j]) <= k)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};