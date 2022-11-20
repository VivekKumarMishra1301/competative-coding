class Solution
{
public:
    bool isUgly(int n)
    {

        if (n < 1)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }
        int i = 2;
        vector<int> hold;
        n = abs(n);
        while (n > 1)
        {
            if (n % 15 == 0)
            {
                n = n / 15;
            }
            else if (n % 10 == 0)
            {
                n = n / 10;
            }
            else if (n % 6 == 0)
            {
                n = n / 6;
            }
            else if (n % 5 == 0)
            {

                n = n / 5;
            }
            else if (n % 3 == 0)
            {
                n = n / 3;
            }
            else if (n % 2 == 0)
            {
                n = n / 2;
            }
            else
            {
                return false;
            }
        }

        // for(int i=0;i<hold.size();i++){
        //     if(hold[i]!=2&&hold[i]!=5&&hold[i]!=3){
        //         return false;
        //     }
        // }
        return true;
    }
};