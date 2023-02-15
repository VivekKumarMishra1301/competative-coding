class Solution
{
public:
    //      void findsub(int i,int n,vector<vector<int>>&hold,vector<int>&temp,vector<int>&nums,set<vector<int>>&st){
    //         if(i==n){

    //             st.insert(temp);
    //             return;
    //         }

    //         findsub(i+1,n,hold,temp,nums,st);
    //         vector<int>newop=temp;

    //                      newop.push_back(nums[i]);

    //         findsub(i+1,n,hold,newop,nums,st);

    //     }
    void findsubop(int ind, vector<int> &temp, vector<vector<int>> &hold, vector<int> &nums)
    {
        hold.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i != ind && nums[i] == nums[i - 1])
            {
                continue;
            }
            temp.push_back(nums[i]);
            findsubop(i + 1, temp, hold, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> hold;
        vector<int> hold1;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        // findsub(0,nums.size(),hold,hold1,nums,st);
        // for(auto &i:st){
        //     hold.push_back(i);
        // }
        findsubop(0, hold1, hold, nums);
        return hold;
    }
};

class Solution
{
public:
    void findsub(int i, int n, vector<vector<int>> &hold, vector<int> &temp, vector<int> &nums, set<vector<int>> &st)
    {
        if (i == n)
        {

            st.insert(temp);
            return;
        }

        findsub(i + 1, n, hold, temp, nums, st);
        vector<int> newop = temp;

        newop.push_back(nums[i]);

        findsub(i + 1, n, hold, newop, nums, st);
    }
    // void findsubop(int ind,vector<int>&temp,vector<vector<int>>&hold,vector<int>&nums){
    //         hold.push_back(temp);
    //         for(int i=ind;i<nums.size();i++){
    //             if(i!=ind&&nums[i]==nums[i-1]){
    //                 continue;
    //             }
    //                 temp.push_back(nums[i]);
    //             findsubop(i+1,temp,hold,nums);
    //             temp.pop_back();
    //         }
    //     }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> hold;
        vector<int> hold1;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        findsub(0, nums.size(), hold, hold1, nums, st);
        for (auto &i : st)
        {
            hold.push_back(i);
        }
        // findsubop(0,hold1,hold,nums);
        return hold;
    }
};