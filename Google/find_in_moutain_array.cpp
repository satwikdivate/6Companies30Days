 #include<bits/stdc++.h>
using namespace std;
 class MountainArray {
   public:
    int get(int index);
    int length();
     };
class Solution {
public:

    int peakfind(MountainArray &arr,int n){
        int start=0,end=n-1;
        int res=-1;

        while(start<end){
            int mid=(start+end)/2;
            if(arr.get(mid+1)>arr.get(mid))
                start=mid+1,res=mid+1;
            else
                end=mid;
        
        }
        return res;

    }

    int bs(int s,int e, MountainArray &arr,int target,bool flg){
        int res=-1;

        if(flg==0){
            while(s<=e){

                int mid=(s+e)/2;
                if(arr.get(mid)==target){
                    res=mid;
                    e=mid-1;
                }else if(arr.get(mid)>target){
                    e=mid-1;
                }else
                    s=mid+1;
            }
          
        }else{
             while(s<=e){

                int mid=(s+e)/2;
                if(arr.get(mid)==target){
                    res=mid;
                    e=mid-1;
                }else if(arr.get(mid)>target){
                    s=mid+1;
                }else
                    e=mid-1;
            }
        }
            return res;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int peak=peakfind(arr,arr.length());
        if(arr.length()<=8){

            for(int i=0;i<arr.length();i++){
                if(arr.get(i)==target)
                    return i;
            }
            return -1;
        }
        int first=bs(0,peak,arr,target,0);
        if(first!=-1)
            return first;
        int second=bs(peak+1,arr.length(),arr,target,1);
        if(second!=-1)
            return second;
        
        return -1;
        
    }
};