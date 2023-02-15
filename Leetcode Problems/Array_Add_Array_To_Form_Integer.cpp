class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int en = num.size() - 1;
        vector<int> hold;
        int carry = 0;
        while (en >= 0 && k > 0)
        {

            hold.push_back((num[en] + k % 10 + carry) % 10);
            // if()
            carry = (num[en] + k % 10 + carry) / 10;
            en--;
            k /= 10;
        }
        while (k > 0)
        {
            hold.push_back((k % 10 + carry) % 10);
            carry = (k % 10 + carry) / 10;
            k /= 10;
        }
        while (en >= 0)
        {
            hold.push_back((num[en] + carry) % 10);
            carry = (num[en] + carry) / 10;
            en--;
        }
        if (carry != 0)
        {
            hold.push_back(carry);
        }
        reverse(hold.begin(), hold.end());
        return hold;
    }
};