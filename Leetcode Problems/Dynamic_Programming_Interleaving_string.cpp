class Solution
{
public:
    map<pair<pair<int, int>, int>, bool> mp;
    bool memo(string s1, string s2, string s3, int l1, int l2, int l3, int i, int j, int k)
    {
        if (k == l3)
        {
            if (i == l1 && j == l2)
            {
                return true;
            }
            return false;
        }

        if (mp.find({{i, j}, k}) != mp.end())
        {
            return mp[{{i, j}, k}];
        }

        if (i == l1)
        {
            if (s2[j] == s3[k])
                return mp[{{i, j}, k}] = memo(s1, s2, s3, l1, l2, l3, i, j + 1, k + 1);
            else
                return mp[{{i, j}, k}] = false;
        }
        if (j == l2)
        {
            if (s1[i] == s3[k])
                return mp[{{i, j}, k}] = memo(s1, s2, s3, l1, l2, l3, i + 1, j, k + 1);
            else
                return mp[{{i, j}, k}] = false;
        }

        bool first = false;
        bool second = false;

        if (s1[i] == s3[k])
        {
            first = memo(s1, s2, s3, l1, l2, l3, i + 1, j, k + 1);
        }
        if (s2[j] == s3[k])
        {
            second = memo(s1, s2, s3, l1, l2, l3, i, j + 1, k + 1);
        }
        return mp[{{i, j}, k}] = first || second;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        return memo(s1, s2, s3, l1, l2, l3, 0, 0, 0);
    }
};