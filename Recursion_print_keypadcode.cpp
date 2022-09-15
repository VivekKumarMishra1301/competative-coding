#include <iostream>
#include <string>
#include <iostream>
#include <string>
using namespace std;
string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int num,string outp=""){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    if(num==0){
        cout<<outp<<endl;
        return;
    }
    int temp=num%10;
    int len = mapping[num % 10].length();
    int cal=num/10;
    for(int i=0;i<len;i++){
        printKeypad(cal,mapping[num % 10][i]+outp);
    }
    
    
   
    
}

using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
