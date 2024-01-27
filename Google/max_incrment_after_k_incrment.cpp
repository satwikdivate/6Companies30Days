 #include<bits/stdc++.h>
using namespace std;
class Solution {
public: static const int m = 1e9 + 7;
    int maximumProduct(vector<int>& arr, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        for(int i=0;i<arr.size();i++){
            q.push(make_pair(arr[i],i));
        }
        int i=0;
        while(i<k){
            auto top=q.top();
            arr[top.second]=arr[top.second]+1;
            q.pop();
            q.push({arr[top.second],top.second});
            i++;
        }
       long long  product=1;
        for(int i=0;i<arr.size();i++){
        
            product=(((product%m)*arr[i])%m);
        }

        return product;
    }
};