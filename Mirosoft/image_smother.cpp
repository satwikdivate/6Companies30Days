     #include<bits/stdc++.h>
using namespace std;
   bool isValid(int i, int j, int n, int m){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {


        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        vector<int> dx = {0, -1, -1, -1, 0, 1, 1, 1,0};
        vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1,0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x = i; int y = j;

                int sum = 0;
                int cnt = 0;

                for(int k = 0; k < 9; k++){
                    int newx = x + dx[k];
                    int newy = y + dy[k];

                    if(isValid(newx, newy, n, m)){
                        sum += img[newx][newy];
                        cnt++;
                    }
                }

                ans[x][y] = sum / cnt;
            }
        }

        return ans;
    }