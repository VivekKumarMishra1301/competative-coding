class Solution
{
public:
    int distinctPrimeFactors(vector<int> &nums)
    {

        vector<long> hold;

        hold.push_back(2);

        int ele = *max_element(nums.begin(), nums.end());
        for (int i = 3; i <= ele; i++)
        {
            bool flag = true;
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                hold.push_back(i);
            }
        }
        for (int i = 0; i < hold.size(); i++)
        {
            cout << hold[i] << " ";
        }
        int count = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            int num = hold[i];
            bool flag = false;
            int el = *max_element(nums.begin(), nums.end());
            if (el == 0)
            {

                break;
            }
            cout << " h";
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % num == 0)
                {
                    while (nums[j] > 0 && nums[j] % num == 0)
                    {
                        nums[j] /= num;
                    }
                    flag = true;
                }
            }
            if (flag)
            {
                count++;
            }
        }

        return count;
    }
};