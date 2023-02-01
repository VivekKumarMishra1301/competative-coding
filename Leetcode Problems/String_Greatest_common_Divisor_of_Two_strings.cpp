class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 == str2)
        {
            return str1;
        }
        string hold = "";

        // for(int i=0;i<str1.size();i++){
        //     if(i<str2.size()&&str1[i]==str2[i]){
        //         hold+=str1[i];
        //     }else{
        //         break;
        //     }
        // }

        string s1 = str1 + str2;
        string s2 = str2 + str1;
        if (s1 == s2)
        {
            int x = __gcd(str1.size(), str2.size());
            for (int i = 0; i < x; i++)
            {
                hold += str1[i];
            }
        }

        return hold;
    }
};