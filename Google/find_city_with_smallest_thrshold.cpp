 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& arr, int distanceThreshold) {
        
        // flod warshall algorithm
        vector<vector<int>>matrix(n+1,vector<int>(n+1,INT_MAX/2));

        for(int i=0;i<arr.size();i++){
            int first=arr[i][0];
            int second=arr[i][1];
            int distance=arr[i][2];
            matrix[first][second]=distance;
            matrix[second][first]=distance;
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(i==j)
                    matrix[i][j]=0;
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
       pair<int,int>ans;
       ans.first=0;
       ans.second=INT_MAX;
          for(int i=0;i<n;i++){
              int count=0;
                for(int j=0;j<n;j++){
                    if(i!=j && matrix[i][j]<=distanceThreshold)
                        count++;
                }
                if(count<=ans.second){
                    ans.second=count;
                    ans.first=i;
                }
                // if(ans.second==count){

                // }
            }
return ans.first;
//  int minCity = -1, minReachable = INT_MAX;
//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         for (int j = 0; j < n; j++) {
//             if (i != j && matrix[i][j] <= distanceThreshold) {
//                 count++;
//             }
//         }
//         if (count <= minReachable) {
//             minReachable = count;
//             minCity = i; // Choose the city with the largest index in case of a tie
//         }
//     }
// return minCity;
    }
};