class Solution
{
public:
    int minMaxDifference(int num)
    {

        string m = to_string(num);
        string n = to_string(num);
        char f = m[0];
        if (f == '9')
        {

            for (int i = 0; i < m.size(); i++)
            {
                if (m[i] < f)
                {
                    f = m[i];
                    break;
                }
            }
        }
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i] == f)
            {
                m[i] = '9';
            }
        }
        f = n[0];
        if (f == '0')
        {
            for (int i = 0; i < n.size(); i++)
            {
                if (n[i] > f)
                {
                    f = n[i];
                    break;
                }
            }
        }

        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == f)
            {
                n[i] = '0';
            }
        }

        int k = stoi(m);
        int l = stoi(n);
        return k - l;
    }
};