class Solution
{
public:
    string reverse(string str)
    {
        int st = 0;
        int en = str.size() - 1;
        while (st <= en)
        {
            swap(str[st], str[en]);
            st++;
            en--;
        }
        return str + ' ';
    }

    string reverseWords(string s)
    {
        int en = s.size() - 1;
        while (s[en] == ' ')
        {
            en--;
        }
        string hold = "";
        string str = "";
        while (en >= 0)
        {
            if (s[en] == ' ' || en == 0)
            {
                if (en == 0 && s[0] != ' ')
                {
                    str += s[0];
                }
                if (str == "")
                {
                    en--;
                    continue;
                }
                hold += reverse(str);
                str = "";
            }
            else
            {
                str += s[en];
            }
            en--;
        }
        // if(hold[hold.size()-1]==' ')
        int l = hold.size() - 1;
        while (hold[l--] == ' ')
            hold.pop_back();
        return hold;
    }
};