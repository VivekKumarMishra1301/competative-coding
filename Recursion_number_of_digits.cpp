#include<iostream>
int count(int n){
    //write your code here
   if(n==0){
       return 0;
   }
    return 1+count(n/10);
}

using namespace std;


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


