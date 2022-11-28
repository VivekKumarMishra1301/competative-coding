class Solution
{
public:
    int romanToInt(string s)
    {
        int icount = 0;
        int m[256];
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int num = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            num = num + m[s[i]];
            if (i != 0 && ((s[i] == 'V' && s[i - 1] == 'I') || (s[i] == 'C' && s[i - 1] == 'X') || (s[i] == 'X' && s[i - 1] == 'I') || (s[i] == 'M' && s[i - 1] == 'C') || (s[i] == 'D' && s[i - 1] == 'C') || (s[i] == 'L' && s[i - 1] == 'X')))
            {
                num = num - m[s[i - 1]];
                i--;
            }
        }
        num = num - icount;
        return num;
    }
};

/*
class Solution {
public:
    int romanToInt(string s) {
        int icount=0;
        int m[256];
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int num=0;
        int num2=m[s[s.size()-1]];
        for(int i=s.size()-1;i>=0;i--){

         if(m[s[i]]<num2){
             num=num-m[s[i]];
         }else{
             num=num+m[s[i]];
         }
           num2=m[s[i]];
            }

        num=num;
        return num;
    }
};

*/