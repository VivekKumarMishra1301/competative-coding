class Solution
{
public:
    int addMinimum(string nums)
    {
        // vector<int>freq(3,0);
        //         for(auto i:word){
        //             freq[i-'a']++;
        //         }

        //         int maxi=max(freq[0],max(freq[1],freq[2]));
        //         int d1=maxi-freq[0];
        //         int d2=maxi-freq[1];
        //         int d3=maxi-freq[2];
        //         return d1+d2+d3;

        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 'a')
            {
                if (nums[i + 1] == 'c')
                {
                    cnt++;
                }
                else if (nums[i + 1] == 'a')
                {
                    cnt += 2;
                }
            }
            else if (nums[i] == 'b')
            {
                if (nums[i + 1] == 'a')
                {
                    cnt++;
                }
                else if (nums[i + 1] == 'b')
                {
                    cnt += 2;
                }
            }
            else
            {
                if (nums[i + 1] == 'b')
                {
                    cnt++;
                }
                else if (nums[i + 1] == 'c')
                {
                    cnt += 2;
                }
            }
        }
        int lind = nums.size() - 1;
        if (nums[lind] == 'a')
        {
            cnt += 2;
        }
        else if (nums[lind] == 'b')
        {
            cnt++;
        }

        if (nums[0] == 'c')
        {
            cnt += 2;
        }
        else if (nums[0] == 'b')
        {
            cnt++;
        }

        return cnt;
    }
};