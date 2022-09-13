#include <iostream>
void mergeSort(int input[], int size){
        if(size <= 1){
            return;
        }
    
    int mid=size/2;
    
    int size1 = mid;
    int size2 = size-mid;
    
    int arr1[500], arr2[500];
    
    for(int i=0;i<size1;i++){
        arr1[i]=input[i];
    }
    
    int l=0;
    
    for(int i=mid;i<size;i++){
        arr2[l++]=input[i];
    }
    
    mergeSort(arr1 , size1);
    mergeSort(arr2 , size2);
    
    int i=0,j=0, k=0;
    //int arr3[size];
    
    while(i<size1 && j<size2){
        if (arr1[i] < arr2[j]) {
            
            input[k++] = arr1[i];
            i++;
            
        }
        else if(arr1[i] > arr2[j]){
            input[k++] = arr2[j];
            j++;
        }
        else{
            input[k++] = arr1[i++];
            input[k++] = arr2[j++];
        }
       
    }
     while (i < size1) {
        input[k++] = arr1[i++];
        
    }
  
    
    while (j < size2) {
        input[k++] = arr2[j++];
        
    }
    
    
   
}


using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}