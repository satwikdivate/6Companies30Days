 #include<bits/stdc++.h>
using namespace std;
 int maxSubarrayLength(vector<int>& arr, int k) {
        int count=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<arr.size()){
            mp[arr[j]]++;

            if(mp[arr[j]]<=k){
                count=max(count,j-i+1);
            }else if(mp[arr[j]]>k){

                while(arr[i]!=arr[j]){
                    mp[arr[i]]--;
                    i++;
                }
                i++;
                mp[arr[j]]--;
            }
            j++;
        }
        return count;
    }