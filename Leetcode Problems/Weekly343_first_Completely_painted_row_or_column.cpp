class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        vector<long> r(mat.size(), 0);
        vector<long> c(mat[0].size(), 0);
        map<int, pair<int, int>> meraMap;
        for (int i = 0; i < mat.size(); i++)
        {
            long s = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                meraMap[mat[i][j]] = {i, j};
                s += (long)mat[i][j];
            }
            r[i] = s;
            // cout<<r[i]<<" ";
        }
        cout << endl;
        for (int i = 0; i < mat[0].size(); i++)
        {
            long s = 0;
            for (int j = 0; j < mat.size(); j++)
            {
                // meraMap[mat[i][j]].insert({i,j});
                s += (long)mat[j][i];
            }
            c[i] = s;
            // cout<<c[i]<<" ";
        }

        for (int i = 0; i < arr.size(); i++)
        {
            pair<int, int> pt = meraMap[arr[i]];
            int x = pt.first;
            int y = pt.second;
            // cout<<x<<y<<" ";
            r[x] -= arr[i];
            c[y] -= arr[i];

            if (r[x] == 0 || c[y] == 0)
            {
                return i;
            }
        }
        return arr.size() - 1;
    }
};