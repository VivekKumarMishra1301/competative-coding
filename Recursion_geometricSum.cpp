#include <iostream>
#include <math.h>
#include <iomanip>
double geometricSum(int k) {
    // Write your code here 
    if(k==0){
        return 1;
    }
	
    // if(k==1){
    //     return 1;
    // }
   double ans=geometricSum(k-1);
    double cal=1;
    for(int i=0;i<k;i++){
        cal=2*cal;
    }
    ans=ans+1/cal;
    return ans;
}



using namespace std;

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
