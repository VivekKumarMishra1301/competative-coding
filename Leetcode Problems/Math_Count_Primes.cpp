class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1 || n == 2)
        {
            return 0;
        }
        //         unordered_map<int,int>meraMap;
        //         // meraMap[2]++;
        //         meraMap[1]++;
        //        for(int i=2;i*i<n;i++){
        //            if(meraMap.count(i)!=0){
        //                continue;
        //            }
        //            int j=i*i;
        //            int k=2;
        //            while(j<n){
        //                if(meraMap.count(j)==0){
        //                    meraMap[j]++;
        //                }
        //                k++;
        //                j=j+i;
        //            }

        //        }
        //         for(auto i:meraMap){
        //             cout<<i.first<<" ";
        //         }
        //         return (n-1)-meraMap.size();

        int hold = 0;
        bool *prime = new bool[n];
        for (int i = 1; i < n; i++)
        {
            prime[i] = true;
        }

        for (int i = 2; i * i < n; i++)
        {
            for (int j = i * i; j < n; j += i)
            {
                if (!prime[j])
                {
                    continue;
                }

                prime[j] = false;
            }
        }

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                hold++;
            }
        }
        return hold;
    }
};