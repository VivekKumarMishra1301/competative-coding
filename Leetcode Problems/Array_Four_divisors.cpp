class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int numofdiv = 0;
            vector<int> hold;
            int square_root = (int)sqrt(nums[i]) + 1;
            for (int j = 1; j < square_root; j++)
            {
                if (hold.size() > 4)
                {
                    break;
                }
                if (nums[i] % j == 0 && j * j != nums[i])
                {

                    hold.push_back(j);
                    hold.push_back(nums[i] / j);
                }

                if (nums[i] % j == 0 && j * j == nums[i])
                    hold.push_back(j);
            }
            if (hold.size() == 4)
            {
                total = total + hold[0] + hold[1] + hold[2] + hold[3];
            }
        }

        return total;
    }
};