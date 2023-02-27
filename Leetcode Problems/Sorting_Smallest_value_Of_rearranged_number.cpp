class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num == 0)
        {
            return 0;
        }
        vector<int> hold;
        while (num != 0)
        {
            hold.push_back(num % 10);
            num /= 10;
        }
        sort(hold.begin(), hold.end());
        if (num < 0)
        {
            reverse(hold.begin(), hold.end());
        }
        int ind = 0;
        if (hold[0] == 0)
        {
            while (ind < hold.size() && hold[ind] == 0)
            {
                ind++;
            }
            swap(hold[0], hold[ind]);
        }

        long long newnum = 0;
        for (int i = 0; i < hold.size(); i++)
        {
            newnum = newnum * 10 + hold[i];
        }
        if (num < 0)
        {
            return 0 - newnum;
        }
        return newnum;
    }
};