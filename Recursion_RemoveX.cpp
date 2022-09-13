#include <iostream>
// Change in the given string itself. So no need to return or print anything

void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return;
    }
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
    }
	if(input[0]=='x'){
        for(int i=0;i<count;i++){
            input[i]=input[i+1];
        }
    }
    if(input[0]=='x'){
         removeX(input);
    }
    removeX(input+1);
}

using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
