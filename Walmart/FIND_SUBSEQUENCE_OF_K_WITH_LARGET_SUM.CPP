 #include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second<b.second)
            return true;
        return false;
    }
class Solution {
public:

    void solve(int index,vector<int>&ds,int currsum,int &sum,int k,vector<int>arr,vector<vector<int>>&ans){

        if(ds.size()==k && currsum >sum){
            sum=currsum;
            if(ans.empty()){
                ans.push_back(ds);
            }else{
                ans.pop_back();
                ans.push_back(ds);
            }
            return;
        }

        if(index==arr.size()){
            return;
        }

        ds.push_back(arr[index]);
        solve(index+1,ds,currsum+arr[index],sum,k,arr,ans);
        ds.pop_back();
        solve(index+1,ds,currsum,sum,k,arr,ans);
    }

   
    vector<int> maxSubsequence(vector<int>& arr, int k) {
               
        if(arr.size()==k)
            return arr;
        priority_queue<pair<int,int>>q;
        for(int i=0;i<arr.size();i++){
            q.push({arr[i],i});
        }

        vector<pair<int,int>>temp;
        while(!q.empty()){
            temp.push_back(q.top());
            q.pop();
        }

        sort(temp.begin(),temp.begin()+k,cmp);
        vector<int>ans;
        int count=0;
       for(auto i:temp){
           if(count==k)
             break;
            ans.push_back(i.first);
           count++;
        

        }
        // sort(ans.begin(),ans.end());
        return ans;
    }
};