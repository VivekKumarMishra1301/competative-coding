/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &arr,int n){
        int st=0;
        int en=n-1;
        int hold=-1;
        while(st<en){
            int mid=(st+en)/2;
            if(arr.get(mid+1)>arr.get(mid)){
                st=mid+1;
                hold=mid+1;
            }else{
                en=mid;
            }
        }
        return hold;
    }
    
    int bs(int s,int e,MountainArray &arr,int target,bool flag){
        int hold=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(target==arr.get(mid)){
                hold=mid;
                if(flag){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }else if(target>arr.get(mid)){
                if(flag){
                    e=mid-1;
                }else{
                    s=mid+1;
                }
            }else{
                if(flag){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
        }
        return hold;
    }
    
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        if(mountainArr.length()<3){
            return -1;
        }
        int pt=peak(mountainArr,mountainArr.length());
        int l=bs(0,pt,mountainArr,target,0);
        if(l!=-1){
            return l;
        }
        
        int r=bs(pt,mountainArr.length()-1,mountainArr,target,1);
        return r;
        
        
    }
};