#include <iostream>
bool checkAB(char input[]) {
	// Write your code here
	if(input[0]=='\0'){
        return true;
    }
    if(input[0]=='a'){
        if(input[1]=='a'||input[1]=='\0'||(input[1]=='b'&&input[2]=='b')){
            if(input[1]=='b'&&input[2]=='b')
            return checkAB(input+3);
            else{
                return checkAB(input+1);
            }
        }else{
            return false;
        }
    }else{
        // if((input[0]=='b'&&input[1]=='b')&&input[2]=='a'){
        //     return checkAB(input+2);
        // }else{
        //     return false;
        // }
        return false;
    }
}




using namespace std;

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
