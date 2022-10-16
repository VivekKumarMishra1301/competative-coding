class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        stack<int> s;
        int carry = 0;
        int sum = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == digits.size() - 1)
            {
                sum = digits[i] + 1 + carry;
                carry = 0;
            }
            else
            {
                sum = digits[i] + carry;
                carry = 0;
            }

            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
                s.push(sum);
            }
            else
            {
                s.push(sum);
            }
        }
        if (carry != 0)
        {
            s.push(carry);
        }
        vector<int> result;
        while (s.empty() == false)
        {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};