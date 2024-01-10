   #include<bits/stdc++.h>
using namespace std;
 vector<int> findDistance(char start, unordered_map<char,list<pair<char,int>>>mp){

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,start-'a'});

        int count=0;
        int totalcount=0;
        int i=0;
        int secondcount=INT_MAX;
        vector<int>distance(36,INT_MAX);
        distance[start-'a']=0;
        while(!q.empty()){

            auto top=q.top();
            q.pop();       
           
            for(auto i:mp[top.second+'a']){
                if(top.first+i.second < distance[i.first-'a']){
                    distance[i.first-'a']=top.first+i.second;
                    q.push({top.first+i.second,i.first-'a'});
                }
            }

        }

        return distance;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        unordered_map<char,list<pair<char,int>>>mp;

        for(int i=0;i<original.size();i++){
            mp[original[i]].push_back({changed[i],cost[i]});
        }

        vector<vector<int>>alldistance(36,vector<int>(36,INT_MAX));
        for(int i=0;i<26;i++){
            alldistance[i]=findDistance('a'+i,mp);
        }
        long long count=0;
        for(int i=0;i<source.size();i++){

            if(source[i]==target[i])
                continue;
            
            if(alldistance[source[i]-'a'][target[i]-'a']==INT_MAX)
                return -1;
            else
                count+=alldistance[source[i]-'a'][target[i]-'a'];
        }

        return count;
    }