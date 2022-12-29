class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> hold(n, vector<int>(n, 0));

        int count = n * n;
        int rs = 0;
        int re = n - 1;
        int cs = 0;
        int ce = n - 1;
        int num = 1;
        while (count > 0)
        {
            for (int i = rs; i <= re; i++)
            {
                hold[cs][i] = num++;

                count--;
            }

            cs++;
            if (count == 0)
            {
                break;
            }
            for (int i = cs; i <= ce; i++)
            {
                hold[i][re] = num++;

                count--;
            }
            re--;

            if (count == 0)
            {
                break;
            }

            for (int i = re; i >= rs; i--)
            {
                hold[ce][i] = num++;

                count--;
            }
            if (count == 0)
            {
                break;
            }

            ce--;

            for (int i = ce; i >= cs; i--)
            {
                hold[i][rs] = num++;

                count--;
            }
            rs++;
        }
        return hold;
    }
};