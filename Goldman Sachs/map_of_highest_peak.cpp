#include<bits/stdc++.h>
using namespace std; 
 vector<vector<int>> highestPeak(vector<vector<int>>& arr) {
         
        queue<pair<pair<int,int>,int>>q;

        vector<vector<int>> visited(arr.size(),vector<int>(arr[0].size(),false));
        vector<vector<int>> ans(arr.size(),vector<int>(arr[0].size(),0));
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1){
                    ans[i][j]=0;
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int h=q.front().second;
            q.pop();
           
            int rowi[]={-1,0,1,0};
            int coli[]={0,-1,0,1};

            for(int i=0;i<4;i++){
                int x=row+rowi[i];
                 int y=col+coli[i];
            
                 if(x>=0 && x<arr.size() && y>=0 && y<arr[0].size() && visited[x][y]==0){
                     ans[x][y]=h+1;
                     visited[x][y]=1;
                     q.push({{x,y},h+1});
                }
        }
           
        }

       
        return ans;
    }