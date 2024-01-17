  #include<bits/stdc++.h>
  using namespace std;
  
  vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        unordered_map<int,int>mp;

        for(int i=0;i<arr.size();i++){

            if(mp.find(arr[i][1])!=mp.end()){
                mp[arr[i][1]]++;
            }else
                mp[arr[i][1]]=0;
        }

        vector<int>notre;
        vector<int>onelost;
        for(int i=0;i<arr.size();i++){

            if(mp.find(arr[i][0])==mp.end())
                notre.push_back(arr[i][0]);
            if(mp[arr[i][1]]==0)
                onelost.push_back(arr[i][1]);
        }
    vector<vector<int>>ans;
    unordered_set a(notre.begin(),notre.end());
    unordered_set b(onelost.begin(),onelost.end());

    vector<int>first(a.begin(),a.end());
    vector<int>second(b.begin(),b.end());
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    ans.push_back(first);
    ans.push_back(second);
    return ans;
    }