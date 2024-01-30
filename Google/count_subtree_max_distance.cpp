 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int solve(int subtree, vector<vector<int>>dist,int n){
        int cntN=0,cntE=0,mxd=0;
        for(int i=0;i<n;i++){
            if(((subtree>>i)&1)==0)
                continue;
            
            cntN++;
            for(int j=i+1;j<n;j++){
                if(((subtree>>j)&1)==0)
                     continue;
                if(dist[i][j]==1)
                    cntE++;
                
                mxd=max(mxd,dist[i][j]);
            }

        }
        if(cntN==cntE+1)
            return mxd;
        return -1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>v(n-1,0);
        vector<vector<int>>dist(15,vector<int>(15,INT_MAX));

        // make adjcency list
        for(auto temp:edges){
            // ASSIGN ALL WEGINGHTS TO 1
            dist[temp[0]-1][temp[1]-1]=1;
            dist[temp[1]-1][temp[0]-1]=1;
        }

        // applay flod warshal to find all distances
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[j][k]==INT_MAX)
                        continue;
                    dist[i][j]=dist[j][i]=min({dist[i][j],dist[j][i],
                    dist[i][k]+dist[k][j]});
                }
            }
        }

        // iterate all the subsets
        for(int i=0;i<(1<<n);i++){
            int ans=solve(i,dist,n);
            if(ans>0)
                v[ans-1]++;
        }
        return v;
    }
};