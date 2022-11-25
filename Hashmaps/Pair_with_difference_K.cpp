#include <iostream>
using namespace std;

#include <unordered_map>
/*int getPairsWithDifferenceK(int *arr, int n, int k) {
    // Write your code here
    unordered_map<int,int>meraMap;
    for(int i=0;i<n;i++){
        meraMap[arr[i]]++;
    }


int count=0;
for(int i=0;i<n;i++){


    int	 diff1=arr[i]-k;

    int	 diff2=arr[i]+k;

if(meraMap.find(diff1)!=meraMap.end()){
    if(meraMap[arr[i]]!=0){

    if(diff1==arr[i]){
        int n=meraMap[arr[i]];
        int m=n-1;
        int mul=m*n;
        count=count+mul/2;
    }else{
        count=count+meraMap[arr[i]]*meraMap[diff1];
    }
    }
}

if (meraMap.find(diff2) != meraMap.end()) {
if(meraMap[arr[i]]!=0){

  if (diff2 == arr[i]) {
    int n = meraMap[arr[i]];
    int m = n - 1;
    int mul = m * n;
    count = count + mul / 2;
  } else {
    count = count + meraMap[arr[i]] * meraMap[diff2];
  }
}

}


meraMap[arr[i]]=0;


}


return count;
}*/
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    // Write your code here
    unordered_map<int, int> map;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int c1 = arr[i] - k;
        int c2 = arr[i] + k;
        if (map.find(c1) != map.end())
            ans += map[c1];
        if (k != 0 && map.find(c2) != map.end())
            ans += map[c2];
        map[arr[i]]++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}