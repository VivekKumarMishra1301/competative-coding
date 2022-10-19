class Solution
{
public:
    int find(vector<int> &nums, int target)
    {

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int result = find(nums, target);
        vector<int> store;
        int st = 0;
        int end = 0;
        if (result == -1)
        {
            store.push_back(-1);
            store.push_back(-1);
            return store;
        }
        else
        {
            for (int i = result + 1; i < nums.size(); i++)
            {
                if (nums[i] != nums[i - 1])
                {
                    end = i - 1;
                    break;
                }
                if (i == nums.size() - 1)
                {
                    end = i;
                }
            }
            if (result == nums.size() - 1)
            {
                end = result;
            }
            for (int i = result - 1; i >= 0; i--)
            {
                if (nums[i] != nums[i + 1])
                {
                    st = i + 1;
                    break;
                }
            }
        }
        store.push_back(st);
        store.push_back(end);
        return store;
        ;
    }
};