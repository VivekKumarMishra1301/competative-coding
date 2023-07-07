class Solution
{
public:
    int maxConsecutiveAnswers(string a, int k)
    {

        int fc = 0;
        int maxi = 0;
        int s = 0;
        int e = 0;
        while (e < a.size())
        {
            if (a[e] == 'F')
            {
                fc++;
            }
            if (fc > k)
            {
                maxi = max(maxi, e - s);
                while (s < a.size() && fc > k)
                {
                    if (a[s] == 'F')
                    {
                        fc--;
                    }
                    s++;
                }
            }
            e++;
        }
        maxi = max(maxi, e - s);

        int tc = 0;
        s = 0;
        e = 0;
        while (e < a.size())
        {
            if (a[e] == 'T')
            {
                tc++;
            }
            if (tc > k)
            {
                maxi = max(maxi, e - s);
                while (s < a.size() && tc > k)
                {
                    if (a[s] == 'T')
                    {
                        tc--;
                    }
                    s++;
                }
            }
            e++;
        }
        maxi = max(maxi, e - s);

        return maxi;
    }
};