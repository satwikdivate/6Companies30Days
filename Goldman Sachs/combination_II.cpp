  #include<bits/stdc++.h>
using namespace std;
 void solve(int i,int sum,int finalsum,int n,int k,vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans){

     
        if(sum>finalsum || ds.size()>k)
            return;
        if(sum==finalsum && ds.size()==k){
            ans.push_back(ds);
            return;
        }
   
       for(int j=i;j<n;j++) {
            ds.push_back(arr[j]);
            solve(j+1,sum+arr[j],finalsum,n,k,ds,arr,ans);
            ds.pop_back();
       }
               
               
    }