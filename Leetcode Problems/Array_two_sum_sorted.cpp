class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> store;
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j)
        {
            if ((numbers[i] + numbers[j]) == target)
            {
                store.push_back(i + 1);
                store.push_back(j + 1);
                return store;
            }
            else if ((numbers[i] + numbers[j]) > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return store;
    }
};