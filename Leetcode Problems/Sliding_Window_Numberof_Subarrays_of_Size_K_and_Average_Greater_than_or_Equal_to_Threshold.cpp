class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {
        long long pref = 0;
        int cnt = 0;
        int st = 0;

        int en = 0;
        while (en <= arr.size() - 1)
        {
            pref += arr[en];
            int s = en - st + 1;
            if (s > k)
            {
                pref = pref - arr[st];
                st++;
            }

            s = en - st + 1;
            if (s == k && (pref / k) >= threshold)
            {
                cnt++;
            }
            en++;
        }

        return cnt;
    }
};