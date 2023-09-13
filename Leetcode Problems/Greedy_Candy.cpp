class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int choco = 0;
        vector<int> toffee(ratings.size(), 1);
        //         for(int i=0;i<ratings.size();i++){
        //             if(i==0){
        //                 if(ratings[i]>ratings[i+1]){
        //                     toffee[i]=toffee[i+1]+1;
        //                 }
        //             }else if(i==ratings.size()-1){
        //                 if(ratings[i]>ratings[i-1]){
        //                     toffee[i]=toffee[i-1]+1;

        //                 }
        //             }else{
        //                 if(ratings[i]>ratings[i-1]&&ratings[i]>ratings[i+1]){
        //                     int maxi=(toffee[i-1],toffee[i+1]);
        //                     toffee[i]=maxi+1;
        //                 }else if(ratings[i]>ratings[i-1]){
        //                     toffee[i]=toffee[i-1]+1;
        //                 }else if(ratings[i]>ratings[i+1]){
        //                     if(toffee[i]<=toffee[i+1]){
        //                         toffee[i]=toffee[i+1]+1;
        //                     }
        //                 }
        //             }
        //         };
        bool flag = false;
        // while(!flag){
        flag = true;
        for (int i = ratings.size() - 1; i >= 0; i--)
        {
            if ((i + 1) < ratings.size() && ratings[i] > ratings[i + 1] && toffee[i] <= toffee[i + 1])
            {
                toffee[i] = toffee[i + 1] + 1;
                flag = false;
            }
        }
        // }

        for (int i = 0; i < ratings.size(); i++)
        {
            if ((i - 1) >= 0 && ratings[i] > ratings[i - 1] && toffee[i] <= toffee[i - 1])
            {
                toffee[i] = toffee[i - 1] + 1;
                flag = false;
            }
        }
        for (auto i : toffee)
        {
            // cout<<i<<" ";
            choco += i;
        }
        return choco;
    }
};