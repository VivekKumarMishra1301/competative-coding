class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        vector<long long> hold;
        if (num % 3 != 0)
        {
            return hold;
        }

        hold.push_back((num / 3) - 1);
        hold.push_back((num / 3));
        hold.push_back((num / 3) + 1);
        return hold;
    }
};