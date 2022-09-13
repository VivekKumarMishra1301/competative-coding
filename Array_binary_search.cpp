int binarySearch(int *input, int n, int val)
{
    int low=0;
      int high=n-1;
      while(low<=high){
      int mid=(low+high)/2;
      if(val==input[mid])
      return mid;
      else if(val>input[mid])
      low=mid+1;
     else
     high=mid-1;
      }
          
    return -1;
    //Write your code here
//     int start=0;
//     int end=n-1;
    
//     while(start<=end){
//         int mid=(start+end)/2;
//         if(val==input[mid]){
//             return mid;
//         }else if(val>input[mid]){
// 			start=mid+1;            
//         }else{
//             end=mid-1;
//         }
//     }
      
}