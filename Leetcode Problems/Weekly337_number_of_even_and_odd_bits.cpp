class Solution
{
public:
    vector<int> evenOddBit(int n)
    {
        string b = bitset<64>(n).to_string();
        vector<int> hold;
        int ec = 0;
        int oc = 0;
        for (int i = 0; i < b.size(); i++)
        {
            if (i % 2 == 0 && b[i] == '1')
            {
                ec++;
            }
            else if (i % 2 != 0 && b[i] == '1')
            {
                oc++;
            }
        }

        hold.push_back(oc);
        hold.push_back(ec);

        return hold;
    }
};