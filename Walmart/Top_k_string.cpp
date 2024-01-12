#include<bits/stdc++.h>
using namespace std;

class cmp{
    public:
    bool operator()(const pair<string,int> &a,const pair<string,int> &b){
        // if same frequency prioritizing by lexicographical order
        if(a.second==b.second) return a.first>b.first; 
        // else prioritize by frequency
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) { 
        //create unordered_map and store words in it
        unordered_map<string,int> s;
        for(auto word:words) s[word]++;
        vector<string> ans;

        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        for(auto &i:s){
            pq.push({i.first,i.second});
        }
        for(int i=0;i<k;i++){
            pair<string,int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
        }   
        return ans;     
    }
};