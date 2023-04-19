class Solution
{
public:
    //     void threesum(vector<int> &nums, int ind, long target, set<vector<int>>&hold)
    //     {
    //         vector<int> store(4);
    //         for (int i = ind; i < nums.size() - 2; i++)
    //         {
    //             int st = i + 1, end = nums.size() - 1;
    //             long sum = target - nums[i];
    //             // if(i==0||(i>0&&nums[i]!=nums[i-1])){
    //             while (st < end)
    //             {
    //                 if ((nums[st] + nums[end]) == sum)
    //                 {
    //                     cout << target << " ";
    //                     store[0] = nums[ind - 1];
    //                     store[1] = nums[i];
    //                     store[2] = nums[st];
    //                     store[3] = nums[end];
    //                     hold.insert(store);
    //                     // cnt++;
    //                     while (st < end && nums[st] == nums[st + 1])
    //                     {
    //                         st++;
    //                     }
    //                     while (st < end && nums[end] == nums[end - 1])
    //                     {
    //                         end--;
    //                     }

    //                     st++;
    //                     end--;
    //                 }
    //                 else if ((nums[st] + nums[end]) < sum)
    //                 {
    //                     st++;
    //                 }
    //                 else
    //                 {
    //                     end--;
    //                 }
    //             }
    //             // }
    //         }
    //     }

    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {

        map<int, int> meraMap;
        for (auto i : nums1)
        {
            for (auto j : nums2)
            {
                meraMap[(i + j)]++;
            }
        }
        int cnt = 0;
        for (auto i : nums3)
        {
            for (auto j : nums4)
            {
                if (meraMap.find(-(i + j)) != meraMap.end())
                    cnt += meraMap[-(i + j)];
            }
        }
        return cnt;

        // vector<int>nums;
        // for(auto i:nums1){
        //     nums.push_back(i);
        // }
        // for(auto i:nums2){
        //     nums.push_back(i);
        // }
        // for(auto i:nums3){
        //     nums.push_back(i);
        // }
        // for(auto i:nums4){
        //     nums.push_back(i);
        // }
        // sort(nums.begin(), nums.end());
        // set<vector<int>> st;
        // int cnt=0;
        // for (int i = 0; i < nums.size() - 3; i++)
        // {
        //     threesum(nums, i + 1, 0 - nums[i], st);
        // }
        // return st.size();
    }
};