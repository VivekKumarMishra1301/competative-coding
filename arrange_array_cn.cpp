/*void arrange(int *arr, int n)
{
    //Write your code here
    int beg=0;
    int end=n-1;
    int i=1;
    if(n>=0&&n<=10000){
    while(i<=n){
      arr[beg]=i;
        beg++;
        i++;
        if(i<n){
        arr[end]=i;
        end--;
        i++;
    }
    }

}
}*/

void arrange(int *arr, int n)
{

    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            arr[j] = i;
            j++;
        }
    }
    for (int i = n; 1 <= i; i--)
    {
        if (i % 2 == 0)
        {
            arr[j] = i;
            j++;
        }
    }

    // Write your code here
}