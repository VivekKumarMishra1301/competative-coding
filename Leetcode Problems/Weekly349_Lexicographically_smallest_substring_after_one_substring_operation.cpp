class Solution
{
public:
    string smallestString(string s)
    {
        // if(s[0]!='a'){
        //     s[0]=s[0]-1;
        //     return s;
        // }else{
        bool flag = false;
        // bool flag
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != 'a')
            {
                s[i] = s[i] - 1;
                flag = true;
                // return s;
            }
            else if (s[i] == 'a' && !flag)
            {
                // s[i]=s[i]-1;
                // flag=false;
                // return s;
                continue;
                // break;
            }
            else if (s[i] == 'a' && flag)
            {
                break;
            }
        }
        // }
        // s[s.size()-1]='z';
        if (!flag)
        {
            s[s.size() - 1] = 'z';
        }

        return s;
    }
};