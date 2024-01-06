  #include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){

    if(a.first==b.first)
        return a.second>b.second;
    // if(a.first<b.first)
        return a.first<b.first;
}
class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& emp) {
        vector<pair<int,int>>arr;

        for(int i=0;i<emp.size();i++){
            arr.push_back(make_pair(emp[i][0],emp[i][1]));
        }
    // sort(arr.begin(),arr.end());
    sort(arr.begin(),arr.end(),cmp);
    vector<int>height;
    for(int i=0;i<arr.size();i++){
        height.push_back(arr[i].second);
    }

    vector<int>ans;
    ans.push_back(height[0]);
    for(int i=1;i<arr.size();i++){

        if(ans.back()<height[i])
            ans.push_back(height[i]);
        else{
            int index=lower_bound(ans.begin(),ans.end(),height[i])-ans.begin();
            ans[index]=height[i];
        }
    }

    return ans.size();
   
    }
};