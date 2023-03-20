class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        //         if(flowerbed.size()==1){
        //             if(flowerbed[0]==0&&n==1)
        //                 return true;
        //             if(flowerbed[0]==1&&n==0)
        //                 return true;

        //             return false;
        //         }
        //         for(int i=1;i<flowerbed.size()-1;i++){
        //             if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0){
        //                 flowerbed[i]=1;
        //                 n--;
        //                 if(!n)
        //                     return true;
        //             }
        //         }

        //         if(!n)
        //             return true;
        //         if(flowerbed[0]==0&&flowerbed[1]==0)
        //             n--;
        //         if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0)
        //             n--;
        //         if(n<=0)
        //             return true;
        //         return false;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (i == 0)
            {
                if (flowerbed[i] == 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                continue;
            }
            if (i == flowerbed.size() - 1)
            {
                if (flowerbed[i] == 0 && i - 1 >= 0 && flowerbed[i - 1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                continue;
            }
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        if (flowerbed.size() == 1 && flowerbed[0] == 0 && n == 1)
            return true;
        if (n <= 0)
            return true;
        return false;
    }
};