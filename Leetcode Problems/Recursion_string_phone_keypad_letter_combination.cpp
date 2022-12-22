class Solution
{
public:
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterComb(string digits)
    {
        if (digits.size() == 0)
        {
            vector<string> op;
            op.push_back("");
            return op;
        }
        vector<string> combinate = letterComb(digits.substr(1));

        vector<string> op;
        int k = digits[0] - 48;

        string concat = keypad[k];

        for (int i = 0; i < concat.size(); i++)
        {
            for (int j = 0; j < combinate.size(); j++)
            {
                op.push_back(concat[i] + combinate[j]);
            }
        }
        return op;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            vector<string> op;

            return op;
        }
        return letterComb(digits);
    }
};