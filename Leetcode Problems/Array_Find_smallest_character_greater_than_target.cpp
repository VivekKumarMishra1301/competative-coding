class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        char hold = letters[0];
        for (int i = 0; i < letters.size(); i++)
        {
            if (letters[i] > target)
            {
                hold = letters[i];
                return hold;
            }
        }
        return hold;
    }
};