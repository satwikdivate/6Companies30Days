
#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int k;
    int n;
    unordered_map<string,int>mp;
// resursion
    // int solve(int prev,int i,vector<int>&arr){

    //     if(i>=n)
    //         return 0;
        
    //     int result=0;
    //     if(prev==-1){

    //         int take=arr[i]+solve(i,i+1,arr);
    //         int nottake=solve(prev,i+1,arr);
    //         result=max(take,nottake);
    //     }else if(i-prev<=k){
    //         int take=arr[i]+solve(i,i+1,arr);
    //         int nottake=solve(prev,i+1,arr);
    //         result=max(take,nottake);
    //     }

    // return result;
    // }


    // a new type memorization
int solve(int prev,int i,vector<int>&arr){

        if(i>=n)
            return 0;
        
        int result=0;
        string res=to_string(prev)+"_"+to_string(i);
        if(mp.find(res)!=mp.end())
            return mp[res];
        if(prev==-1){

            int take=arr[i]+solve(i,i+1,arr);
            int nottake=solve(prev,i+1,arr);
            result=max(take,nottake);
        }else if(i-prev<=k){
            int take=arr[i]+solve(i,i+1,arr);
            int nottake=solve(prev,i+1,arr);
            result=max(take,nottake);
        }

    return mp[res]= result;
    }
    // int solve(in)

    int constrainedSubsetSum(vector<int>& nums, int kk) {
         n=nums.size();
        k=kk;
        // int result= solve(-1,0,nums);
        // if(result==0)
        //     return result+=*max_element(begin(nums),end(nums));
        // return result;

        vector<int>dp(nums.begin(),nums.end());

        priority_queue<pair<int,int>>q;
        int result=nums[0];
        q.push({dp[0],0});
        for(int i=1;i<nums.size();i++){

            // condition is not satisfing so pop
            while(!q.empty() && i-q.top().second > k){
                // if(result+q.top().first>dp[i]){}
                q.pop();
            }

            // condition satisfing
            dp[i]=max(dp[i],nums[i]+q.top().first);
            q.push({dp[i],i});
            result=max(result,dp[i]);
        }
        return result;
    }   
};