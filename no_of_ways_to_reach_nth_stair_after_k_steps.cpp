#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007; // Define modulo as a constant

int f(vector<vector<int>>&dp,int pos,int k,int end){

    if(k==0){
        return (pos==end)?1:0;
    }

    if(dp[pos][k]!=-1)
        return dp[pos][k]%MOD;
    
    return dp[pos][k]=(f(dp,pos+1,k-1,end)%MOD+f(dp,pos-1,k-1,end)%MOD)%MOD;
}

    int numberOfWays(int startPos, int endPos, int k) {
        // if(abs(startPos-endPos)%2!=k%2) return 0;
        vector<vector<int>> dp(3003,vector<int>(1001,-1));
        return f(dp,startPos+k,k,endPos+k);
    }