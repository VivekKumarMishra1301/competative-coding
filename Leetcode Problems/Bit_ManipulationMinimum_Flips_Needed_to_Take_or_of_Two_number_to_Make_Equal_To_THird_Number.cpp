class Solution
{
public:
    void decToBinary(int n, vector<int> &first)
    {
        // array to store binary number
        int binaryNum[32];

        // counter for binary array
        int i = 0;
        while (n > 0)
        {

            // storing remainder in binary array
            first.push_back(n % 2);
            n = n / 2;
            i++;
        }
    }

    int minFlips(int a, int b, int c)
    {
        vector<int> first;
        vector<int> sec;
        vector<int> th;
        decToBinary(a, first);
        decToBinary(b, sec);
        decToBinary(c, th);
        int sz = max(first.size(), max(sec.size(), th.size()));
        while (first.size() < sz)
        {
            // first.insert(first.begin(), 0);
            first.push_back(0);
        }
        while (sec.size() < sz)
        {
            // sec.insert(sec.begin(), 0);
            sec.push_back(0);
        }
        while (th.size() < sz)
        {
            // th.insert(th.begin(), 0);
            th.push_back(0);
        }
        int cnt = 0;
        for (int i = 0; i < sz; i++)
        {
            cout << first[i] << " " << sec[i] << ":" << th[i] << endl;
            if ((first[i] | sec[i]) == th[i])
            {
                continue;
            }
            if (th[i] == 0)
            {
                if (first[i] != 0)
                {
                    cnt++;
                }
                if (sec[i] != 0)
                {
                    cnt++;
                }
            }

            if (th[i] == 1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};