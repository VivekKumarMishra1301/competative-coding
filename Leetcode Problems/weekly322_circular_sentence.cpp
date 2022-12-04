class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        char first = sentence[0];
        for (int i = 1; i < sentence.size(); i++)
        {
            if ((i - 2) >= 0 && sentence[i - 1] == ' ')
            {
                if (sentence[i] != sentence[i - 2])
                {
                    return false;
                }
            }
        }
        if (sentence[sentence.size() - 1] != first)
        {
            return false;
        }
        return true;
    }
};