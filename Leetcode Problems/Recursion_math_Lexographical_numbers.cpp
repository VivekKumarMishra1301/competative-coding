class Solution
{
public:
    void insert(int i, int n, vector<int> &hold)
    {
        if (i > n)
        {
            return;
        }

        hold.push_back(i);
        for (int k = 0; k < 10; k++)
        {
            insert(i * 10 + k, n, hold);
        }
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> hold;
        for (int i = 1; i <= 9; i++)
        {
            insert(i, n, hold);
        }
        return hold;
    }
};