#include<bits/stdc++.h>
using namespace std;

// whwne we have choice of adding only 1
int minMoves2(vector<int>& arr) {
        // simple median approach
        int ans=0;
        sort(arr.begin(),arr.end());
        int mediaIndex=arr.size()/2;
        for(int i=0;i<arr.size();i++){
            ans+=abs(arr[i]-arr[mediaIndex]);
        }

        return ans;
    }

    // whwen we have choivce of adding 1-n-1 elenmnt 
     int minMoves(vector<int>& arr) {
          int ans=0;
        // we want to take n-1 alrray element so find minmum element from array and  subtract it from all toher element
        int index=INT_MAX;
        for(int i=0;i<arr.size();i++){
            index=min(index,arr[i]);
        }

        for(int i=0;i<arr.size();i++){
            ans+=abs(arr[i]-index);
        }

        return ans;
    }