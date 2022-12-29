class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> hold;
        int count = matrix.size() * matrix[0].size();
        int rs = 0;
        int re = matrix[0].size() - 1;
        int cs = 0;
        int ce = matrix.size() - 1;
        while (count > 0)
        {
            for (int i = rs; i <= re; i++)
            {

                hold.push_back(matrix[cs][i]);
                count--;
            }

            cs++;
            if (count == 0)
            {
                break;
            }
            for (int i = cs; i <= ce; i++)
            {

                hold.push_back(matrix[i][re]);
                count--;
            }
            re--;

            if (count == 0)
            {
                break;
            }

            for (int i = re; i >= rs; i--)
            {
                hold.push_back(matrix[ce][i]);
                count--;
            }
            if (count == 0)
            {
                break;
            }

            ce--;

            for (int i = ce; i >= cs; i--)
            {
                hold.push_back(matrix[i][rs]);
                count--;
            }
            rs++;
        }
        return hold;
    }
};