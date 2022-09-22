#include <iostream>
using namespace std;
void helper(int input[], int n, int output[], int m,int k)
{
    if (n <= 0)
    {
	int sum=0;
    for(int i=0;i<m;i++){
        sum=sum+output[i];
    }
    if(sum==k){
     for(int i=0;i<m;i++){
        cout<<output[i]<<" ";
    }  
        cout<<endl;
    }
        return;
    }
    int newout[100000];
    for (int i = 0; i < m; i++)
    {
        newout[i] = output[i];
    }
    newout[m] = input[0];
    helper(input + 1, n - 1, newout, m + 1,k);
    helper(input + 1, n - 1, output, m,k);
   
}





void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    
     int output[100000];
    int m = 0;
    helper(input, size, output, m,k);
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
