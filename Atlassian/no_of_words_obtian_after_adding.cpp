 #include<bits/stdc++.h>
using namespace std;
 int wordCount(vector<string>& s, vector<string>& t) {
        unordered_map<string,int>u1;
        int n=s.size(),m=t.size();
        for(int i=0;i<n;i++){  
            for(char ch='a';ch<='z';ch++){
                string temp=s[i];
                temp+=ch;
                sort(temp.begin(),temp.end());
                u1[temp]++;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            sort(t[i].begin(),t[i].end());
            if(u1[t[i]]>0)ans++;
        }
        return ans;

    }