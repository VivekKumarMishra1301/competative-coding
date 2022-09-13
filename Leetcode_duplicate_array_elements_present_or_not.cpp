class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> s;
        ? // Same logic as ascii array storing the values at a index and incresing the value at that index if element is found and iterating the storing array and if we got the element requal to 2 or more at any index we will simply return the false .
            for (int i = 0; i < nums.size(); i++)
        {
            s[nums[i]]++;
        }

        for (auto it : s) // ITERATORS
        {
            if (it.second >= 2)
            {
                return true;
            }
        }
        return false;
        return -1;
    }
};