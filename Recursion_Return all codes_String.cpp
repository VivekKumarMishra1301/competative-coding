#include <iostream>
#include <string.h>
using namespace std;

int m=0;
void helper(string input,string output[10000],string op){
      if (input.length()==0){
          output[m++]=op;
          
          return;
      }
     char c1=(input[0]-48)+96;
      if(input[0]=='0')
        return;
     
     helper(input.substr(1),output,op+c1);
     if(input.size()>1){
        int d=(input[0]-48)*10+(input[1]-48);
        if(d>26)
            return;
        char c2=96+d;
        helper(input.substr(2),output,op+c2);
    }
    
}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    	string op="";
    int n=0;
      	helper(input,output,op);
    
    return m;
    
}


using namespace std;

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
