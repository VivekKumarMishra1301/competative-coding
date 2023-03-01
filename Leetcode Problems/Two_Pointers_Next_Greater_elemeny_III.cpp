class Solution
{
public:
    int nextGreaterElement(int n)
    {
        if (n >= INT_MAX)
        {
            return -1;
        }
        int numb = n;
        vector<int> hold;
        while (numb != 0)
        {
            hold.push_back(numb % 10);
            numb /= 10;
        }
        //         string num="";
        //         for(int i=hold.size()-1;i>=0;i--){
        //             string k=to_string(hold[i]);
        //             num+=k;
        //         }

        //         sort(hold.begin(),hold.end());
        //         reverse(hold.begin(),hold.end());
        //         string num2="";
        //         for(int i=0;i<hold.size();i++){
        //             string k=to_string(hold[i]);
        //             num2+=k;
        //         }
        //         if(num2>num){
        //             return stoi(num2);
        //         }
        //         return -1;

        reverse(hold.begin(), hold.end());
        int size = hold.size();
        bool flag = false;
        int ind = 0;
        for (int i = size - 2; i >= 0; i--)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (hold[j] > hold[i])
                {
                    swap(hold[j], hold[i]);
                    ind = i;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            return -1;
        }
        for (int i = ind + 1; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (hold[i] > hold[j])
                {
                    swap(hold[i], hold[j]);
                }
            }
        }

        long num = 0;
        for (int i = 0; i < size; i++)
        {
            num = num * 10 + hold[i];
            if (num > INT_MAX)
            {
                return -1;
            }
        }
        if (num <= n)
        {
            return -1;
        }
        return num;
    }
};