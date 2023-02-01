#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        for (int i = 1; i <= x; i++)
        {
            if ((i - 1) % 2 == 0)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
        // 	    vector<int>hold;
        // 	    if(x==1){
        // 	        cout<<1<<endl;
        // 	        continue;
        // 	    }

        // 	    if(x==2){
        // 	        cout<<10<<" "<<13<<endl;
        // 	        continue;
        // 	    }

        // 	  for(int i=2;i<=x;i++){
        // 	      bool flag=true;
        // 	      for(int j=2;j<=i/2;j++){
        // 	          if(i%j==0){
        // 	              flag=false;
        // 	              break;
        // 	          }
        // 	      }
        // 	      if(flag){
        // 	          hold.push_back(i);
        // 	      }
        // 	  }

        // 	  cout<<-300<<" ";
        // 	  int sum=abs(-300);
        // 	  for(int i=2;i<=x;i++){

        // 	  }
    }
    return 0;
}
