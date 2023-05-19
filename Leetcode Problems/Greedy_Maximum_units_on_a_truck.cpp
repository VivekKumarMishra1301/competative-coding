class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        //      double val1 = ((double)(a[1]) / a[0]);
        // double val2 = ((double)(b[1]) / b[0]);
        return a[1] > b[1];
    }

    int fKnap(vector<vector<int>> &arr, int cap, int n)
    {
        sort(arr.begin(), arr.end(), compare);
        int p = 0;
        int cw = 0;
        for (int i = 0; i < n; i++)
        {
            if (cw + arr[i][0] <= cap)
            {
                p += (arr[i][1] * arr[i][0]);
                cw += arr[i][0];
            }
            else
            {
                int nw = cap - cw;
                p += arr[i][1] * (nw);
                return p;
            }
            return p;
        };

        int maximumUnits(vector<vector<int>> & boxTypes, int truckSize)
        {
            return fKnap(boxTypes, truckSize, boxTypes.size());
        }
    };