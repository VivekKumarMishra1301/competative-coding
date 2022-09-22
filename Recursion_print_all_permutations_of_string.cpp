#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
void permute(string a, int l, int r){
    if(l==r){
        cout<<a<<endl;
    }
    else{
        for(int i=l; i<=r; i++){
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
void printPermutations(string input){
    permute(input,0,input.size()-1);

    
}







int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}