class Solution
{
public:
    bool isvowel(char ch) { return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U'); }
    string reverseVowels(string s)
    {
        int st = 0;
        int end = s.size() - 1;
        while (st < end)
        {
            while (!isvowel(s[st]) && st < end)
            {
                st++;
            }
            while (end > st && !isvowel(s[end]))
            {
                end--;
            }
            swap(s[st], s[end]);
            st++;
            end--;
        }
        return s;
    }
};