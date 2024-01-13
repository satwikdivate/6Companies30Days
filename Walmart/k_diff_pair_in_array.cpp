#include<bits/stdc++.h>
using namespace std;
int findPairs(vector<int>& arr, int k) {
        
     map<pair<int,int>,int>mp;
    sort(arr.begin(),arr.end());
    int count=0;
        for(int i=0;i<arr.size()-1;i++){

            for(int j=i+1;j<arr.size();j++){
                int diff=abs(arr[i]-arr[j]);

                if(diff==k){
                    if( mp.find({arr[i],arr[j]})==mp.end()){
                        count++;
                        mp[{arr[i],arr[j]}]++;
                    }
                }
            }
        }

        return count;
    }