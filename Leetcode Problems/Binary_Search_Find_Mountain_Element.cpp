class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int st = 0;
        int en = arr.size() - 1;
        int maxi = 0;
        while (st < en)
        {
            int mid = (st + en) / 2;

            if (arr[mid] > arr[maxi])
            {
                maxi = mid;
            }
            if (arr[mid] < arr[mid + 1])
            {
                st = mid + 1;
            }
            else
            {
                en = mid;
            }
        }
        return maxi;
    }
};