#include <iostream>
/* input - Input String
 *  output - Save the result in the output array (passed as argument). You don’t have to
 *  print or return the result
 */
/* input - Input String
 *  output - Save the result in the output array (passed as argument). You don’t have to
 *  print or return the result
 */
/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
void minLengthWord(char input[], char output[]){
		
	// Write your code here	
    int count=0,st=0,end=0,min=100000000,sti=0;
    for(int i=0;input[i]!='\0';i++){
        if(input[i]!=' '&&input[i+1]!='\0'){
            count++;
        }else if(input[i+1]=='\0'){
            if(count<min){
            min=count;
            end=i+1;
                sti=st;
            }
        }
        else{ 
            
            if(count<min){
            min=count;
            end=i;
                sti=st;
            }
            count=0;
            
            st=i+1;
        }
        
    }
    int k=0;
    for(int i=sti;i<=end;i++){
        if(i!=end){
            output[k]=input[i];
            k++;
        }else{
            output[k]='\0';
        }
    }
    

}




using namespace std;

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
