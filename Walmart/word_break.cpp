#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
    int n;

    int solve(int i,string s,vector<string>& dictionary){

        if(i==s.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=n;

        for(string res :dictionary){
            int wlen=res.size();
            if(i+wlen<=s.size() && s.substr(i,wlen)==res){
                int extra=solve(i+wlen,s,dictionary);
                ans=min(ans,extra);
            }
        }

        int noextra=1+solve(i+1,s,dictionary);
        ans=min(noextra,ans);
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.size();
        dp.assign(s.size()+1,-1);
        return solve(0,s,dictionary);
    }
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int temp=minExtraChar(s,wordDict);
        if(temp==0)
            return true;
        else
            return false;
    }
};