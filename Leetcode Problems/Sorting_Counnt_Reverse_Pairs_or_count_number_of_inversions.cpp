class Solution
{
public:
    long long merge(vector<int> &arr, long long st, long long en, long long mid)
    {
        long long sz = en - st + 1;
        long long ind = st;
        vector<long long> arr2(sz);
        long long i = 0;
        long long k = mid + 1;
        long long cnt = 0;

        long long m = st;
        long long j = mid + 1;
        long long right = en;
        long long mid2 = mid + 1;
        while (m < mid2 && j <= right)
        {
            if ((long long)arr[m] > 2 * (long long)arr[j])
            {
                cnt += (mid2 - m);
                j++;
            }
            else
                m++;
        }

        while (st <= mid && k <= en)
        {
            if (arr[st] < arr[k])
            {
                arr2[i++] = arr[st++];
            }
            else if (arr[st] > arr[k])
            {
                // cnt+=(mid-st+1);
                arr2[i++] = arr[k++];
            }
            else
            {
                arr2[i++] = arr[st++];
                arr2[i++] = arr[k++];
            }
        }
        while (st <= mid)
        {
            arr2[i++] = arr[st++];
        }
        while (k <= en)
        {
            arr2[i++] = arr[k++];
        }
        for (int i = 0; i < sz; i++)
        {
            arr[ind++] = arr2[i];
        }
        return cnt;
    }

    long long mergeSort(vector<int> &arr, long long st, long long en)
    {
        if (st >= en)
        {
            return 0;
        }
        long long mid = (st + en) / 2;
        long a = mergeSort(arr, st, mid);
        long long b = mergeSort(arr, mid + 1, en);
        long long c = merge(arr, st, en, mid);
        return a + b + c;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};