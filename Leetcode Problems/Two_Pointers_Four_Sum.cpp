class Solution
{
public:
    void threesum(vector<int> &nums, int ind, long target, set<vector<int>> &hold)
    {
        vector<int> store(4);
        for (int i = ind; i < nums.size() - 2; i++)
        {
            int st = i + 1, end = nums.size() - 1;
            long sum = target - nums[i];
            // if(i==0||(i>0&&nums[i]!=nums[i-1])){
            while (st < end)
            {
                if ((nums[st] + nums[end]) == sum)
                {
                    cout << target << " ";
                    store[0] = nums[ind - 1];
                    store[1] = nums[i];
                    store[2] = nums[st];
                    store[3] = nums[end];
                    hold.insert(store);
                    while (st < end && nums[st] == nums[st + 1])
                    {
                        st++;
                    }
                    while (st < end && nums[end] == nums[end - 1])
                    {
                        end--;
                    }

                    st++;
                    end--;
                }
                else if ((nums[st] + nums[end]) < sum)
                {
                    st++;
                }
                else
                {
                    end--;
                }
            }
            // }
        }
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> hold;
        if (nums.size() < 4)
        {
            return hold;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            threesum(nums, i + 1, target - nums[i], st);
        }
        for (auto i : st)
        {
            hold.push_back(i);
        }

        return hold;
    }
};