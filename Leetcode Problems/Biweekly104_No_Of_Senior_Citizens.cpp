class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int cnt = 0;
        for (auto i : details)
        {
            string st = "";
            st += i[11];
            st += i[12];
            int nu = stoi(st);
            if (nu > 60)
            {
                cnt++;
            }
        }
        return cnt;
    }
};