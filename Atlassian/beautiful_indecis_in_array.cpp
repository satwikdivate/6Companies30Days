#define pb push_back
 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void preprocess(vector<int>&b, string p){
        int i=0, j=-1;b[0]=-1;
        while(i<p.length()){
            while(j>=0 && p[i]!=p[j])j=b[j];
            i++;j++;
            b[i]=j;
        }
        return;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ma=a.length(), mb=b.length(), n=s.length();
        vector<int>bb(max(ma,mb)+1, 0);
        vector<pair<int,int>>vis;
        vector<int>mp(n,-1);
        vector<int>ans;
        preprocess(bb, b);
        
        int i=0,j=0,c;
        pair<int,int>t;
        while(i<n){
            while(j>=0 && s[i]!=b[j])j=bb[j];
            i++;j++;
            if(j==mb){
                c = i-j;
                if(vis.empty() || (max(c-k, 0)>vis.back().second))vis.pb({max(c-k, 0), min(c+k, n-1)});
                else{
                    t = vis.back();
                    vis.pop_back();
                    vis.pb({t.first, min(c+k, n-1)});
                }
                j=bb[j];
            }
        }
        for(int i=0;i<vis.size();i++){
            for(int j=vis[i].first;j<=vis[i].second;j++)mp[j]=0;
        }
        bb.clear();i=0;j=0;
        preprocess(bb, a);
        
        while(i<n){
            while(j>=0 && s[i]!=a[j])j=bb[j];
            i++;j++;
            if(j==ma){
                c = i-j;
                if(mp[c]==0)ans.pb(c);
                j=bb[j];
            }
        }
        return ans;
    }
};