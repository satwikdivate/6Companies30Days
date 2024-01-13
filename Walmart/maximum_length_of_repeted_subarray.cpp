 #include<bits/stdc++.h>
using namespace std;
 int findLength(vector<int>& arr1, vector<int>& arr2) {
        vector<vector<int>>dp(arr1.size()+1,vector<int>(arr2.size()+1,0));
        int maxlength=0;
        for(int i=1;i<=arr1.size();i++){

            for(int j=1;j<=arr2.size();j++){

                if(arr1[i-1]==arr2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    maxlength=max(maxlength,dp[i][j]);
                }else
                    dp[i][j]=0;
            }
        }
        return maxlength;
    }