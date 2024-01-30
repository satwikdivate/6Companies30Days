#include <iostream>
#include <string>
using namespace std;
 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> smallestTrimmedNumbers(vector<string>& arr, vector<vector<int>>& queries) {
        
       vector<int>ans;

       for(int i=0;i<queries.size();i++){

           vector<pair<string,int>>temp;
           
           for(int j=0;j<arr.size();j++){
               string s(arr[j].begin()+arr[j].size()-queries[i][1],arr[j].end());
               temp.push_back(make_pair(s,j));
           }
           sort(temp.begin(),temp.end());
           ans.push_back(temp[queries[i][0]-1].second);
       }

       return ans;
    }

};