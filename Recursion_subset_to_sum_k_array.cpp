#include <iostream>
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
    {{2, 1, 4},	// Length of this subset is 2
    {2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/
/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int helper(int input[],int n,int outp[][50]){
    if (n == 0)
    {
        outp[0][0] = 0;
        return 1;
    }

		int count = helper(input + 1, n - 1, outp);
    int i, j;
    for (i = 0; i < count; i++)
    {
        outp[count + i][0] = outp[i][0] + 1;
        outp[count + i][1] = input[0];
    }

    for (i = 0; i < count; i++)
    {
        for (j = 1; j < outp[count + i][0]; j++)
        {
            outp[count + i][j + 1] = outp[i][j];
        }
        
       
        
    }
    return 2 * count;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    output[0][0]=0;
    int m=1;
    int outp[10000000][50];
    int smallsize= helper(input,n,outp);
    
    for(int i=1;i<smallsize;i++){
        int sum=0;
        for(int j=1;j<=outp[i][0];j++){
            sum=sum+outp[i][j];
        }
        
        if(sum==k){
           output[m][0]=outp[i][0];
            for(int j=1;j<=outp[i][0];j++){
            output[m][j]=outp[i][j];
        }
            m++;
        }
    }
   
    return m;

}


using namespace std;

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
