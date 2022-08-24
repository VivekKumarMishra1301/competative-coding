#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int mat[1000][1000], smat[1000][1000] =
                         {0};
// bool safe(int x,int y,int n){
//     if(x>=n||x<0||y>=n||y<0||){
//         return true;
//     }else{
//         return false;
//     }
// };
void rat(int x, int y, int n, string ans)
{
    if (x == n - 1 && y == n - 1)
    {
        cout << ans << " ";
        return;
    }

    // if(safe(x,y,n)){
    //
    //     if(rat(x+1,y,n)){
    //         return true;
    //     }
    //      if(rat(x,y+1,n)){
    //         return true;
    //     }
    //     smat[x][y]=0;
    //     return false;
    // }else{
    //     return false;
    // }
    if (x >= n || x < 0 || y >= n || y < 0 || smat[x][y] == 1 || mat[x][y] == 0)
    {

        return;
    }
    smat[x][y] = 1;
    rat(x - 1, y, n, ans + "T");
    rat(x + 1, y, n, ans + "D");
    rat(x, y - 1, n, ans + "L");
    rat(x, y + 1, n, ans + "R");
    smat[x][y] = 0;
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string res = "";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             smat[i][j]=0;

    //         }
    //     }
    rat(0, 0, n, res);
    //      for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             cout<<smat[i][j]<<" ";

    //         }
    //          cout<<endl;
    //     }

    return 0;
}
