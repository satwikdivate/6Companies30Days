#include<bits/stdc++.h>
using namespace std;
 int numberOfSubarrays(vector<int>& arr, int k) {
     
     for(int i=0;i<arr.size();i++){

       if(arr[i]%2==0)  
            arr[i]=0;
        else
            arr[i]=1;
     }


    unordered_map<int,int>mp;
    mp[0]=1;
    int currsum=0;
    int count=0;
     for(int i=0;i<arr.size();i++){
         currsum+=arr[i];

         int requiresum=currsum-k;
         if(mp.find(requiresum)!=mp.end())
            count+=mp[requiresum];
        
        mp[currsum]++;
     }
     return count;
     
    }